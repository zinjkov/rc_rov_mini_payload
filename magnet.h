#pragma once
#include <Arduino.h>
#include "stdint.h"
namespace rc_rov {
	class magnet
	{
	public:
		magnet(uint8_t pin);
		~magnet();
		void init();
		void write(int8_t p);
		int8_t get();
	public:
		uint8_t m_pin;
		int8_t m_val;
	};
}

