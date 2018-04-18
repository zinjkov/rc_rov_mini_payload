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
	m_man.write(m_angle);
}

void servo_manipulator::write(const rov_types::rov_mini_control & control)
{
	m_val = constrain(control.manipulator, -2, 2);
	m_angle += m_val;
	m_angle = constrain(m_angle, 0, 180);
	m_man.write(m_angle);

}

void servo_manipulator::commit(rov_types::rov_mini_telimetry & telimetry)
{
	telimetry.manipulator_feedback = m_angle;
}

