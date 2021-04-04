//
// Created by Diego Santos Seabra on 03/04/21.
//

#ifndef MARIO_AUDIO_H
#define MARIO_AUDIO_H

#include <fmod.hpp>

enum AudioChannel
{
    SFX,
    MUSIC
};

namespace Audio
{
    void init();

    // Creates the sfx and music channels for future use
    void createChannels();

    FMOD::Sound createSound(int audioModes = 0);

    // Just for tests
    void playTitle();

    /**
     *  By default, playing a sound will play with the following configurations:
     *  - No Loop
     *  - 2D Mode (ignores any 3d processing)
     */
    void playSound(int options);
    void stopSound();

    // Volume control
    void setVolume(AudioChannel channel, float volume);

    void stopAll(AudioChannel channel);

    void shutdown();
}


#endif //MARIO_AUDIO_H
