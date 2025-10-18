// GameState.hpp
#pragma once
#include <vector>

class GameState
{
public:
    static GameState &get()
    {
        static GameState instance;
        return instance;
    }

private:
    GameState() = default;
};