#include "acoustics.h"


acoustics::acoustics(int pinIndex) : m_val(0) {
	_pinIndex = pinIndex;
}

void acoustics::init()
{
	pinMode(_pinIndex, OUTPUT);
}

void acoustics::write(int8_t open_close) {
	if (open_close > 0) {
		_needOpen = true;
	}
	if (open_close < 0) {
		_needOpen = false;
	}
	open_close = m_val;
	_nextStep = millis() + STEP;
	_count = -1;
}

void acoustics::run() {
	if (m_val == 0) {
		return;
	}

	unsigned long time = millis();
	if (time < _nextStep) return;
	if (_count == -1)
		_signalLvl = 0;

	_signalLvl = 255 - _signalLvl;
	analogWrite(_pinIndex, _signalLvl);
	_count++;
	_nextStep = time + STEP;

	if (_needOpen && _count > COUTNTOOPEN || !_needOpen && _count > COUTNTOCLOSE) {
		_count = -1;
		_nextStep += STEP;
	}
}

bool acoustics::IsOpen() {
	return _needOpen;
}

int8_t acoustics::get() const
{
	return m_val;
}
