#include "TimedBool.h"
#include <Arduino.h>

TimedBool::TimedBool()
  : _state(false)
  , _start(0)
  , _duration(0) {
}

TimedBool::TimedBool(unsigned long duration)
  : _state(false)
  , _start(0)
  , _duration(duration) {
}

TimedBool::TimedBool(unsigned long duration, bool state)
  : _state(state)
  , _start(millis())
  , _duration(duration) {
}

void TimedBool::setDuration(unsigned long duration) {
  _duration = duration;
}

unsigned long TimedBool::getDuration() {
  return _duration;
}

void TimedBool::setState(bool state) {
  _state = state;
  _start = millis();
}

bool TimedBool::getState() {
  validate();
  return _state;
}

TimedBool::operator bool() {
  return getState();
}

TimedBool& TimedBool::operator=(bool state) {
  setState(state);
  return *this;
}

void TimedBool::validate() {
  if (_start == 0 || _duration == 0) return;

  if (millis() - _start >= _duration) {
    _state = !_state;
    _start = 0;
  }
}