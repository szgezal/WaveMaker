//
// Created by szgeza on 10/02/2023.
//

#include "Oscillator.h"
#include <math.h>
#include <iostream>

#define TWO_PI (3.14159 * 2)
#define AMPLITUDE 0.3 //3.14159

int Oscillator::setFrequency(int fr) {
    frequency = fr;
    return frequency;
}

void Oscillator::setSampleRate(int32_t sR) {
    sampleRate = sR;
}

void Oscillator::setWaveOn(bool isWaveOn) {
    isWaveOn_.store(isWaveOn);
    if (!isWaveOn) phase_ = 0;
}

void Oscillator::render(float *audioData, int32_t numFrames) {

    if (!isWaveOn_.load()) phase_ = 0;

    for (int i = 0; i < numFrames; i++) {

        if (isWaveOn_.load()) {

            // Calculates the next sample value for the sine wave.
            audioData[i] = (float) (sin(phase_) * AMPLITUDE); //phase_ < AMPLITUDE ? AMPLITUDE : 0; //

            // Increments the phase, handling wrap around.
            phase_ += (TWO_PI * frequency) / (double) sampleRate;
            if (phase_ > TWO_PI) phase_ -= TWO_PI;

        } else {
            // Outputs silence by setting sample value to zero.
            audioData[i] = 0;
        }
    }
}