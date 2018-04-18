#include <Arduino.h>
#include "mini_payload.h"

rc_rov::mini_payload mp;

void setup() {
	Serial.begin(115200);
	mp.init();
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
	mp.run();
}


void serialEvent() {
	mp.on_serial_event();
}
