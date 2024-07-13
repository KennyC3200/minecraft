#include "player.hpp"

void Player::init(Window *window, Keyboard *keyboard, Mouse *mouse) {
    this->window = window;
    this->keyboard = keyboard;
    this->mouse = mouse;

    camera.init(window, mouse);
}

void Player::update() {
    // handle movement
    if (keyboard->keys[GLFW_KEY_TAB].pressed) {
        mouse->toggled = !mouse->toggled;
    }
    if (keyboard->keys[GLFW_KEY_W].down) {
        camera.position += 10.0f * (float) window->time_delta * camera.front;
        std::cout << 'W' << std::flush;
    }
    if (keyboard->keys[GLFW_KEY_S].down) {
        camera.position -= 10.0f * (float) window->time_delta * camera.front;
        std::cout << 'S' << std::flush;
    }
    if (keyboard->keys[GLFW_KEY_A].down) {
        camera.position -= 10.0f * (float) window->time_delta * glm::normalize(glm::cross(camera.front, camera.up));
        std::cout << 'A' << std::flush;
    }
    if (keyboard->keys[GLFW_KEY_D].down) {
        camera.position += 10.0f * (float) window->time_delta * glm::normalize(glm::cross(camera.front, camera.up));
        std::cout << 'D' << std::flush;
    }

    camera.update();
}

void Player::render() {
    // TODO: implement third-person
}
