#include "servo_manipulator.h"
#include "rov_hw_config.h"


servo_manipulator::servo_manipulator() : m_val(0), m_angle(90)
{
	
}


servo_manipulator::~servo_manipulator()
{
}

void servo_manipulator::init()
{
	m_man.attach(rc_rov::man_cfg::pin);
	Serial.println("attached");
	m_man.write(m_angle);
	m_timer.start();
	m_is_updated = true;
}

void servo_manipulator::write(const rov_types::rov_mini_control & control)
{

	m_val = constrain(control.manipulator, -2, 2);
	rotate();

	/*
	if (m_val != control.manipulator) {
		m_timer.stop();
		m_timer.start();
		m_val = constrain(control.manipulator, -2, 2);
		rotate();
		m_is_updated = true;
		Serial.println("write");
	}
	
	if (m_timer.elapsed() > 30 || m_is_updated) {
		Serial.println("write2");
		rotate();
		m_is_updated = false;
		m_timer.stop();
		m_timer.start();

	}
	*/
	

}

void servo_manipulator::commit(rov_types::rov_mini_telimetry & telimetry)
{
	telimetry.manipulator_feedback = m_angle;
}

void servo_manipulator::rotate()
{
	//Serial.println(m_angle);
	m_angle += m_val;
	m_angle = constrain(m_angle, 0, 180);
	m_man.write(m_angle);
	delay(15);
}

