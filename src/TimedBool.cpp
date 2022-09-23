#include "TimedBool.h"
#include <Arduino.h>

TimedBool::TimedBool()
  : _value(false)
  , _start(0)
  , _expiration(0) {
}

TimedBool::TimedBool(unsigned long expiration)
  : _value(false)
  , _start(0)
  , _expiration(expiration) {
}

TimedBool::TimedBool(unsigned long expiration, bool value)
  : _value(value)
  , _start(millis())
  , _expiration(expiration) {
}

void TimedBool::setExpiration(unsigned long expiration) {
  _expiration = expiration;
}

unsigned long TimedBool::getExpiration() {
  return _expiration;
}

void TimedBool::setValue(bool value) {
  _value = value;
  _start = millis();
}

bool TimedBool::getValue() {
  validate();
  return _value;
}

TimedBool::operator bool() {
  return getValue();
}

TimedBool& TimedBool::operator=(bool value) {
  setValue(value);
  return *this;
}

void TimedBool::validate() {
  if (_start == 0 || _expiration == 0) return;

  if (millis() - _start >= _expiration) {
    _value = !_value;
    _start = 0;
  }
}