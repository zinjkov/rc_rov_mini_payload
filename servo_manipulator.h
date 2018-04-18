#pragma once
#include <Servo.h>
#include "rov_data_types.hpp"
class servo_manipulator
{
public:
	servo_manipulator();
	~servo_manipulator();
	void init();
	void write(const rov_types::rov_mini_control &control);
	void commit(rov_types::rov_mini_telimetry &telimetry);

private:
	Servo m_man;
	uint8_t m_pin;
	int8_t m_val;
	int m_angle;
};

