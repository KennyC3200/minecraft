#pragma once

#define GLFW_INCLUDE_NONE
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>

#include "crosshair.hpp"
#include "hotbar.hpp"
#include "../util/util.hpp"
#include "../gfx/window.hpp"
#include "../gfx/renderer.hpp"
#include "../world/world.hpp"
#include "../player/player.hpp"

#define UI_RESET_BUTTON(id, assignment)\
ImGui::SameLine();\
if (ImGui::Button("Reset##"#id))\
    assignment

#define UI_INT(label, value) ImGui::Text(#label": %i", value);
#define UI_FLOAT(label, value) ImGui::Text(#label": %.2f", value);

#define UI_VEC3(label, vec) ImGui::Text(#label": %.2f %.2f %.2f", (vec).x, (vec).y, (vec).z);
#define UI_IVEC3(label, vec) ImGUi::Text(#label": %i %i %i", (vec).x, (vec).y, (vec).z);

class UI {
public:
    void init(Window *window, Renderer *renderer, World *world, Player *player);
    void destroy();
    void render();

    Crosshair crosshair;
    Hotbar hotbar;

    bool toggled;
    struct {
        bool toggled;
    } overview;
    struct {
        bool toggled;
        bool demo_window;
    } settings;
private:
    void init_imgui(GLFWwindow *window);
    void render_components();
    void render_overview();
    void render_settings();

    ImGuiIO *io;
    int reset_button_id;

    Window *window;
    Renderer *renderer;
    World *world;
    Player *player;
};
