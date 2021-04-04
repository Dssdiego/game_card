//
// Created by Diego Santos Seabra on 03/04/21.
//

#ifndef MARIO_CONTENT_H
#define MARIO_CONTENT_H

#include <fmod.hpp>

enum SpriteName
{
    COIN,
    EXTRA_LIFE,
    QUESTION
};

enum SoundName
{
    TITLE,
    OVERWORLD
};

namespace Content
{
    void loadSprites();
    void loadTextures();
    void loadSounds();

    // Sounds
    FMOD::Sound getSound(SoundName sound);

    void loadAll();
}


#endif //MARIO_CONTENT_H
