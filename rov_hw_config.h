#pragma once
#include <stdint.h>
#include <Arduino.h>

namespace rc_rov {
	struct motor_cfg {
		enum : uint8_t {
			one_left = 2,
			one_right = 3,

			two_left = 4,
			two_right = 5,

			three_left = 6,
			three_right = 7,

			four_left = 8,
			four_right = 9,
		};
		enum : uint8_t {
			size = 4
		};
	};

	struct magnet_cfg {
		enum : uint8_t {
			hw_pin = 10
		};
	};

	struct acoustics_cfg {
		enum : uint8_t {
			pin = A1
		};
	};
	struct man_cfg {
		enum : uint8_t {
			pin = 11
		};
	};
}


