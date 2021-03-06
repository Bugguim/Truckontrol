#include <Wire.h>
#include "settings.h"
#include "RoadTractor.h"
#include "FlySkyIBus/FlySkyIBus.h"

// Communication
FlySkyIBus IBus;

// Tractor
RoadTractor tractor;

void setup () {
  // Communication
  IBus.begin(Serial);
  Wire.begin(i2cMasterAddress);

  // Tractor
  tractor.initPins(p_motor, p_servo, p_lights);
}

void loop() {
  // Receive Commands
  IBus.loop();
  // Drive Tractor
  tractor.setSpeed(IBus.readChannel(ch_motor));
  tractor.turn(IBus.readChannel(ch_servo));
  tractor.setLight(IBus.readChannel(ch_lights));
}