//
// Created by Diego Santos Seabra on 04/04/21.
//

#include <fstream>
#include "config.h"

Config::Config()
{
    // Init with default values
    setVsync(false);
    setFullscreen(false);
}

Config::~Config()
{

}

void Config::readFile()
{
    std::ifstream fileStream("assets/configs/config.txt", std::ios::in);

    if (!fileStream.is_open())
        std::cerr << "Could not read config file! " << "File does not exist." << std::endl;

    // TODO: Make able to continue with default values if config file is not present

    std::string currentLine;
    std::string nextLine;
    while (!fileStream.eof())
    {
        std::getline(fileStream, currentLine);

        if (!currentLine.empty())
        {
            std::getline(fileStream, nextLine);

            uint32_t firstBracket = currentLine.find('[') + 1;
            uint32_t lastBracket = currentLine.find(']');

            std::string option = currentLine.substr(firstBracket, lastBracket - firstBracket);

            if (option == "vsync")
            {
                setVsync(toBool(nextLine));
            }

            if (option == "fullscreen")
            {
                setFullscreen(toBool(nextLine));
            }
        }
    }
}

bool Config::isVsync() const
{
    return vsync;
}

void Config::setVsync(bool vsync)
{
    Config::vsync = vsync;
}

bool Config::isFullscreen() const
{
    return fullscreen;
}

void Config::setFullscreen(bool fullscreen)
{
    Config::fullscreen = fullscreen;
}

bool Config::toBool(const std::string &s)
{
    return s != "false";
}