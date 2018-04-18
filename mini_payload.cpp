#include "mini_payload.h"
#include "rov_data_types.hpp"


rc_rov::mini_payload::mini_payload() : m_magnet(magnet_cfg::hw_pin),
		m_is_update(false), 
		m_acoustics(acoustics_cfg::pin)
{
}


rc_rov::mini_payload::~mini_payload()
{
}

void rc_rov::mini_payload::init()
{
	Serial.begin(115200);
	m_motors.init();
	m_magnet.init();
	m_acoustics.init();

	m_timeout.start();
}

void rc_rov::mini_payload::run()
{
	write();
	commit();
	send();
}

void rc_rov::mini_payload::write()
{
	if (m_is_update) {
		for (int i = 0; i < motor_cfg::size; i++) {
			m_motors.write(i, m_control.twisting_motors[i]);
		}
		m_magnet.write(m_control.magnet);
		m_acoustics.write(m_control.acoustics);
		m_manipulator.write(m_control);
	}
	m_acoustics.run();
}

void rc_rov::mini_payload::commit()
{
	m_telimetry.mini_communicator_feedback = 1;
	m_telimetry.magnet = m_magnet.get();
	m_telimetry.acoustics = m_acoustics.get();
	m_manipulator.commit(m_telimetry);
}

void rc_rov::mini_payload::send()
{
	if (m_timeout.elapsed() > 100) {
		m_timeout.stop();
		uint8_t buffer[30];
		uint8_t size = m_telimetry.serialize(buffer);
		Serial.write(buffer, size);
		m_timeout.start();
	}
}

void rc_rov::mini_payload::on_serial_event()
{
	uint8_t packet[30];
	rov_types::rov_mini_control hc;
	size_t i = 0;
	delay(1);
	while (Serial.available()) {
		packet[i++] = Serial.read();
	}
	auto e = hc.deserialize(packet, i);
	if (rov_types::serializable::check_for_success(e)) {
		m_control = hc;
		m_is_update = true;
	}

}
