#pragma once

#include "gfx/window.hpp"
#include "gfx/renderer.hpp"
#include "input/keyboard.hpp"
#include "input/mouse.hpp"

class Game {
public:
    Game();
    ~Game();

    void init();
    void loop();
    void destroy();
private:
    void update();
    void render();

    Window window;
    Renderer renderer;
    World world;

    Keyboard keyboard;
    Mouse mouse;
};
