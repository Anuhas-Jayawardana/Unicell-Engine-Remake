#include "Audio/AudioManager.h"

namespace Unicell {
    AudioManager::AudioManager()
    {
        ma_result result;
        result = ma_engine_init(NULL,&engine);
        if(result != MA_SUCCESS){
            std::cout<<"Failed to create the Audio Backends"<<std::endl;
        }
    }

    // TODO : Fix this thing...
    ma_sound AudioManager::load(const char* path)
    {
        ma_result result;
        ma_sound sound;

        result = ma_sound_init_from_file(&engine,path,0,NULL,NULL,&sound);

        if(result != MA_SUCCESS){
            std::cout<<"Failed to load Sound file "<<path<<std::endl;
        }
        return sound;
    }

    void AudioManager::Play(ma_sound sound)
    {
        ma_sound_start(&sound);
    }

    void AudioManager::Play(const char* path){
        ma_engine_play_sound(&engine,path,NULL);
    }

}