#include "Motors.h"
#include <Arduino.h>

namespace rc_rov {
	Motors::Motors()
	{
		m_motors[0].set(motor_cfg::one_left, motor_cfg::one_right);
		m_motors[1].set(motor_cfg::two_left, motor_cfg::two_right);
		m_motors[2].set(motor_cfg::three_left, motor_cfg::three_right);
		m_motors[3].set(motor_cfg::four_left, motor_cfg::four_right);
	}

	Motors::~Motors()
	{
	}

	void Motors::init()
	{
		for (int i = 0; i < motor_cfg::size; i++) {
			m_motors[i].init();
		}
	}

	void Motors::write(uint8_t idx, int8_t power)
	{
		if (idx < motor_cfg::size) {
			m_motors[idx].write(power);
		}
	}

	void Motors::write(int8_t p1, int8_t p2, int8_t p3, int8_t p4)
	{
		int i = 0;
		m_motors[i++].write(p1);
		m_motors[i++].write(p2);
		m_motors[i++].write(p3);
		m_motors[i++].write(p4);
	}

	void Motors::write(int8_t * buffer)
	{
		for (int i = 0; i < motor_cfg::size; i++) {
			m_motors[i].write(buffer[i]);
		}
	}

	motor::motor()
	{
	}

	motor::motor(uint8_t l_, uint8_t r_) : m_left(l_), m_right(r_)
	{
	}

	motor::~motor()
	{
	}

	void motor::set_power(int8_t p_)
	{
		if (p_ == 0) {
			write(LOW, LOW);
		}
		if (p_ == 1) {
			write(HIGH, LOW);
		}
		if (p_ == -1) {
			write(LOW, HIGH);
		}
	}

	void motor::init()
	{
		pinMode(m_left, OUTPUT);
		pinMode(m_right, OUTPUT);
	}

	void motor::write(int8_t pl_, int8_t pr_)
	{
		digitalWrite(m_left, pl_);
		digitalWrite(m_right, pr_);
	}
}