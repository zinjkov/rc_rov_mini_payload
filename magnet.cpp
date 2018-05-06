#include "magnet.h"

rc_rov::magnet::magnet(uint8_t pin) : m_pin(pin)
{
}

rc_rov::magnet::~magnet()
{
}

void rc_rov::magnet::init()
{
	pinMode(m_pin, OUTPUT);
	digitalWrite(m_pin, HIGH);
}

void rc_rov::magnet::write(int8_t p)
{
	m_val = p;
	if (p == 0) {
		digitalWrite(m_pin, HIGH);
	}
	else {
		digitalWrite(m_pin, LOW);
	}
}

int8_t rc_rov::magnet::get()
{
	return m_val;
}
