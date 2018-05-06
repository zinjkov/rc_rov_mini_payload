#pragma once
#include <Servo.h>
#include "rov_data_types.hpp"
#include "timer.h"
class servo_manipulator
{
public:
	servo_manipulator();
	~servo_manipulator();
	void init();
	void write(const rov_types::rov_mini_control &control);
	void commit(rov_types::rov_mini_telimetry &telimetry);

private:
	void rotate();
	Servo m_man;
	uint8_t m_pin;
	int8_t m_val;
	int m_angle;
	timer m_timer;
	bool m_is_updated;
};

	