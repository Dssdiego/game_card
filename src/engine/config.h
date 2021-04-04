//
// Created by Diego Santos Seabra on 04/04/21.
//

#ifndef MARIO_CONFIG_H
#define MARIO_CONFIG_H

#include <iostream>

class Config
{
public:
    Config();
    ~Config();

    void readFile();

    [[nodiscard]] bool isVsync() const;
    void setVsync(bool vsync);
    [[nodiscard]] bool isFullscreen() const;
    void setFullscreen(bool fullscreen);

private:
    bool vsync;
    bool fullscreen;

    bool toBool(std::string const& s);
};

#endif //MARIO_CONFIG_H
