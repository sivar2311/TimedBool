#pragma once

class TimedBool {
  public:
    TimedBool();
    TimedBool(unsigned long expiration);
    TimedBool(unsigned long expiration, bool value);

    void setExpiration(unsigned long expiration);
    unsigned long getExpiration();

    void setValue(bool value);
    bool getValue();

    operator bool();
    TimedBool& operator=(bool value);
  protected:
    void validate();

  protected:
    bool _value;
    unsigned long _start;
    unsigned long _expiration;
};