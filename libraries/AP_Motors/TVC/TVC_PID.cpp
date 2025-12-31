#include <AP_Motors/TVC/TVC_PID.h>


LinearPIDController::LinearPIDController(double _p, double _i, double _d, double _iMax){
  this->p = _p;
  this->i = _i;
  this->d = _d;
  this->previousTimestamp = 0;
  this->previousError = 0;
  this->iMax = _iMax;
  this->lastOutput = 0;
  this->gain = 1.0;
  this->dFilter = NULL;
}

void LinearPIDController::setGain(double inGain){
  this->gain = inGain;
}

double LinearPIDController::update(unsigned long timestamp, float currentValue, float targetValue, bool saturated){
  double currentError = targetValue - currentValue;
  unsigned long deltaMillis = timestamp - this->previousTimestamp;
  double derivative = 0;

  if(this->previousTimestamp != 0) {
    if(deltaMillis == 0) {
      return this->lastOutput;
    }
    // this might not be necessary.
    // this->maybeResetIntegral(currentError);

    double deltaSeconds = deltaMillis / 1000.0;
    if(saturated && fabs(currentError) > 1e-9 && this->integral / currentError < 0) {
      // we are in an overshoot scenario and I term is dissipating. Do not block I term change.
      saturated = false;
    }
    if(!saturated) {
      this->integral += this->gain * this->i * currentError * deltaSeconds;
    }
    if(this->integral > this->i * this->iMax) {
      this->integral = this->i * this->iMax;
    } else if(this-> integral < -(this->i * this->iMax)) {
      this->integral = -(this->i * this->iMax);
    }
    decayI();
    if(fabs(deltaSeconds) > 1e-9) {
      derivative = (currentError - this->previousError) / deltaSeconds;
      if(this->dFilter != NULL) {
        derivative = this->dFilter->filterIn(derivative);
      }
    }
  } 
  this->previousError = currentError;
  this->previousTimestamp = timestamp;
  this->lastOutput = (this->gain * this->p * currentError) + this->integral + (this->gain * this->d * derivative);
  return this->lastOutput;
}

void LinearPIDController::reset(){
  this->previousTimestamp = 0;
  this->integral = 0;
  this->previousError = 0;
}

void LinearPIDController::decayI() {
  // no action for now
  // this might be useful at a val like 0.9999
  // this->integral *= 0.9999;
}

void LinearPIDController::maybeResetIntegral(double currentError){
  if(fabs(this->previousError) < 1e-9) {
    return;
  }
  if(currentError / this->previousError < 0) {
    this->integral = 0;
  }
}
void LinearPIDController::useDFilter(int cutoffFreq, double sampleTime) {
  this->dFilter = new CustomFilter((double)cutoffFreq, sampleTime, IIR::ORDER::OD2, IIR::TYPE::LOWPASS);
}

