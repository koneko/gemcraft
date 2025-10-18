#include <iostream>
#include <vector>
#include <memory>
#include <raylib.h>

#include "game_state.hpp"
#include "game_object.hpp"
#include "menu.hpp"

int main()
{
    const int SCREEN_WIDTH = 1920;
    const int SCREEN_HEIGHT = 1080;

    float dt;

    auto &longLiving = GameState::get().longLiving;
    auto &objects = GameState::get().objects;
    auto &ui = GameState::get().ui;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "gemcraft c++");
    SetTargetFPS(60);

    GameState::get().changeScene(std::make_unique<Menu>());
    while (WindowShouldClose() == false)
    {
        dt = GetFrameTime();

        // --------------------------------------
        // Game objects
        // --------------------------------------
        for (auto &obj : objects)
            if (obj->active)
                obj->Update(dt);

        // --------------------------------------
        // UI objects
        // --------------------------------------
        for (auto &obj : ui)
            if (obj->active)
                obj->Update(dt);

        // --------------------------------------
        // Objects that do not get deleted upon scene change.
        // --------------------------------------
        for (auto &obj : longLiving)
            if (obj->active)
                obj->Update(dt);

        BeginDrawing();
        ClearBackground(BLACK);

        for (auto &obj : objects)
            if (obj->active)
                obj->Draw();

        for (auto &obj : ui)
            if (obj->active)
                obj->Draw();

        for (auto &obj : longLiving)
            if (obj->active)
                obj->Draw();

        EndDrawing();
    }

    CloseWindow();
}