//
// Created by Dillon Yao on 10/31/17.
//

#ifndef OSMIUM_VIEWPORT_H
#define OSMIUM_VIEWPORT_H

#include <stdlib.h>
#include <SFML/Window.hpp>

class Viewport {

private:
    size_t width, height;
    sf::Window _window;

public:
    Viewport();

    Viewport(size_t width, size_t height);
};

#endif //OSMIUM_VIEWPORT_H
