#include <jni.h>
#include <android/input.h>
#include "AudioEngine.h"

static AudioEngine *audioEngine = new AudioEngine();

extern "C" {

JNIEXPORT int JNICALL
Java_com_example_wavemaker_MainActivity_touchEvent(JNIEnv *env, jobject obj, jint action, jint pos_y) {
    switch (action) {
        case AMOTION_EVENT_ACTION_DOWN:
            audioEngine->setToneOn(true);
            break;
        case AMOTION_EVENT_ACTION_UP:
            audioEngine->setToneOn(false);
            break;
        case AMOTION_EVENT_ACTION_MOVE:
            return audioEngine->setFrequency(pos_y);
        default:
            break;
    }
    return pos_y;
}

JNIEXPORT void JNICALL
Java_com_example_wavemaker_MainActivity_startEngine(JNIEnv *env, jobject /* this */) {
    audioEngine->start();
}

JNIEXPORT void JNICALL
Java_com_example_wavemaker_MainActivity_stopEngine(JNIEnv *env, jobject /* this */) {
    audioEngine->stop();
}

}