//
// Created by szgeza on 10/02/2023.
//

#ifndef WAVEMAKER_OSCILLATOR_H
#define WAVEMAKER_OSCILLATOR_H

#include <atomic>
#include <stdint.h>

class Oscillator {
public:
    void setWaveOn(bool isWaveOn);
    void setSampleRate(int32_t sampleRate);
    void render(float *audioData, int32_t numFrames);
    int setFrequency(int fr);

private:
    std::atomic<bool> isWaveOn_{false};
    double phase_ = 0.0;
    double phaseIncrement_ = 0.0;
    int frequency = 440;
    double sampleRate = 0.0;
};

#endif //WAVEMAKER_OSCILLATOR_H
