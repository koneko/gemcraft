#include <iostream>
#include <vector>
#include <memory>
#include <raylib.h>
#include "game_object.hpp"

int main()
{
    const int SCREEN_WIDTH = 1920;
    const int SCREEN_HEIGHT = 1080;

    float dt;
    std::vector<std::unique_ptr<GameObject>> objects;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "gemcraft c++");
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        dt = GetFrameTime();

        for (auto &obj : objects)
            if (obj->active)
                obj->Update(dt);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (auto &obj : objects)
            if (obj->active)
                obj->Draw();

        EndDrawing();
    }

    CloseWindow();
}