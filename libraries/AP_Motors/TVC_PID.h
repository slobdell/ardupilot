#pragma once

#include "TVC_Filters.h"

#ifndef LINEARPIDCONTROLLER_CLASS_DEFINED
#define LINEARPIDCONTROLLER_CLASS_DEFINED
class LinearPIDController {
  private:
    //double p;
    //double i;
    // double d;
    unsigned long previousTimestamp;
    double previousError;

    double iMax;
    void maybeResetIntegral(double currentError);
    void decayI();
    double lastOutput;
    double gain;
    CustomFilter *dFilter;
  public:
    // temp public
    double p;
    double i;
    double d;
    double integral;

    LinearPIDController(double _p, double _i, double _d, double _iMax);
    double update(unsigned long timestamp, float currentValue, float targetValue, bool saturated);
    void reset();
    void setGain(double gain);
    void useDFilter(int cutoffFreq, double sampleTime);
};
#endif // LINEARPIDCONTROLLER_CLASS_DEFINED
