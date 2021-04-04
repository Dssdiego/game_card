//
// Created by Diego Santos Seabra on 03/04/21.
//

#include <iostream>
#include <fmod_errors.h>
#include "audio.h"

FMOD_RESULT result;
FMOD::System *audioSystem;

FMOD::ChannelGroup *sfxChannel;
FMOD::ChannelGroup *musicChannel;
FMOD::Channel *titleChannel;

// TODO: FMOD Documentation
//  https://fmod.com/resources/documentation-api?version=2.0&page=core-api-channel.html

void Audio::init()
{
    result = FMOD::System_Create(&audioSystem);
    if(result != FMOD_OK)
    {
        std::cout << "Error creating FMOD Audio System!" << std::endl;
        std::cout << "Error: " << FMOD_ErrorString(result) << std::endl;
        exit(EXIT_FAILURE);
    }

    // Initialize FMOD
    result = audioSystem->init(512, FMOD_INIT_NORMAL, 0);
    if(result != FMOD_OK)
    {
        std::cout << "Error initializing FMOD Audio System!" << std::endl;
        std::cout << "Error: " << FMOD_ErrorString(result) << std::endl;
        exit(EXIT_FAILURE);
    }

    createChannels();
}

void Audio::createChannels()
{
    audioSystem->createChannelGroup("sfx", &sfxChannel);
    audioSystem->createChannelGroup("music", &musicChannel);
}

void Audio::playTitle()
{
    int audioModes = FMOD_DEFAULT;
    FMOD::Sound *sound;
    audioSystem->createSound("assets/sounds/title.mp3", audioModes, nullptr, &sound);
    audioSystem->playSound(sound, musicChannel, false, &titleChannel);

    // NOTE: Channel is the interface that controls a sound.
    //  In the channel is possible to play/pause/stop a sound.
    //  Probably the way to control sounds is to have one channel
    //  for each sound
}

void Audio::setVolume(AudioChannel channel, float volume)
{
    switch (channel)
    {
        case SFX:
            sfxChannel->setVolume(volume);
            break;
        case MUSIC:
            musicChannel->setVolume(volume);
            break;
    }
}

void Audio::stopAll(AudioChannel channel)
{

}

void Audio::shutdown()
{
    sfxChannel->release();
    musicChannel->release();

    // TODO: Release all loaded sounds

    if (audioSystem != nullptr)
    {
        audioSystem->release();
    }
}
