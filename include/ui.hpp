#pragma once
#include "raylib.h"

class UI
{
public:
    Vector2 position{0, 0};
    float rotation = 0.0f;
    bool active = true;

    UI() = default;
    virtual ~UI() = default;

    virtual void Update(float deltaTime) {}

    virtual void Draw() const {}
};