#pragma once
#include "rov_hw_config.h"
#include "step_motor.h"
namespace rc_rov {
	class motor {
	public:
		motor();
		motor(uint8_t l_, uint8_t r_);
		~motor();
		void set_power(int8_t p_);
		void init();
	private:
		uint8_t m_left;
		uint8_t m_right;
		void write(int8_t pl_, int8_t pr_);
	};

	class Motors
	{
	public:
		Motors();
		~Motors();
		void init();
		void write(uint8_t idx, int8_t power);
		void write(int8_t p1, int8_t p2, int8_t p3, int8_t p4);
		void write(int8_t *buffer);
    int8_t get(int idx);
	private:
		step_motor m_motors[motor_cfg::size];
	};

};
