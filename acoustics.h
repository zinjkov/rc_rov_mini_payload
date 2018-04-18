#ifndef ACUSTIC_HPP
#define ACUSTIC_HPP

#include <Arduino.h>

class acoustics {
public:
	acoustics(int pinIndex);
	void init();
	void write(int8_t open_close);
	void run();
	bool IsOpen();
	int8_t get() const;

private:
	const int STEP = 20;
	const int COUTNTOOPEN = 3;
	const int COUTNTOCLOSE = 5;

	int _count = -1;
	int _signalLvl = 0;
	int _pinIndex;
	bool _needOpen = false;
	int8_t m_val;
	unsigned long _nextStep;
};

#endif
