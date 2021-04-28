//
// Created by Diego Santos Seabra on 21/04/21.
//

#ifndef MARIO_FACE_H
#define MARIO_FACE_H

#include "../engine/math/vec2.h"

/// Back face of the cards
enum FaceType {
    Win,
    Normal,
    Space
};

class Face
{
public:
    Face(int atlasIndex, FaceType faceType);
private:
    int atlasIndex;
    Vec2 position;
    FaceType faceType;
};


#endif //MARIO_FACE_H
