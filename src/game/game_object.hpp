#pragma once
#include "raylib.h"

class GameObject
{
public:
    Vector2 position{0, 0};
    float rotation = 0.0f;
    bool active = true;

    GameObject() = default;
    virtual ~GameObject() = default;

    virtual void Update(float deltaTime) {}

    virtual void Draw() const {}
};