#pragma once
#include "Motors.h"
#include "magnet.h"
#include "rov_data_types.hpp"
#include "timer.h"
#include "acoustics.h"
#include "servo_manipulator.h"
namespace rc_rov {
	class mini_payload
	{
	public:
		mini_payload();
		~mini_payload();
		void init();
		void run();
		void on_serial_event();
	private:
		void write();
		void commit();
		void send();
		Motors m_motors;
		magnet m_magnet;
		rov_types::rov_mini_control m_control;
		rov_types::rov_mini_telimetry m_telimetry;
		bool m_is_update;
		timer m_timeout;
		acoustics m_acoustics;
		servo_manipulator m_manipulator;
	};

}

