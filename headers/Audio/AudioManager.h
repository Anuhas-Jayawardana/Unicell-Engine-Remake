#pragma once

#include "miniaudio/miniaudio.h"
#include <iostream>

typedef ma_sound AudioClip;

namespace Unicell {

class AudioManager {
public:
    AudioManager();

    // TODO : Fix loading :(
    ma_sound load(const char* path);
    void Play(ma_sound sound);
    void Play(const char* path);
private:
    ma_engine engine;
};

}