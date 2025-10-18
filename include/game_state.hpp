#pragma once
#include <vector>
#include <memory>
#include "game_object.hpp"
#include "ui.hpp"
#include "scene.hpp"

class GameState
{
public:
    static GameState &get()
    {
        static GameState instance;
        return instance;
    }

    void changeScene(std::unique_ptr<Scene> scene)
    {
        currentScene = std::move(scene);
        objects.clear();
        ui.clear();
        currentScene->load();
    }

    std::vector<std::unique_ptr<GameObject>> longLiving;
    std::vector<std::unique_ptr<GameObject>> objects;
    std::vector<std::unique_ptr<UI>> ui;

    std::unique_ptr<Scene> currentScene;

private:
    GameState() = default;
};