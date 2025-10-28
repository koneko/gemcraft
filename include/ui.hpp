#pragma once
#include <raylib.h>

class UI
{
public:
    Vector2 position{0, 0};
    float rotation = 0.0f;
    int zIndex;
    bool active = true;

    UI() = default;
    virtual ~UI() = default;

    virtual void Update(float deltaTime);

    virtual void Draw();

    virtual void OnClick();

    virtual void OnMouseOver();
};