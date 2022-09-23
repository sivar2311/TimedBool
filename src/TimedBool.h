#pragma once

class TimedBool {
  public:
    TimedBool();
    TimedBool(unsigned long duration);
    TimedBool(unsigned long duration, bool state);

    void setDuration(unsigned long duration);
    unsigned long getDuration();

    void setState(bool state);
    bool getState();

    operator bool();
    TimedBool& operator=(bool state);
  protected:
    void validate();

  protected:
    bool _state;
    unsigned long _start;
    unsigned long _duration;
};