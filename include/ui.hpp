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
    ~UI() = default;

    void Update(float deltaTime);

    void Draw();

    void OnClick();

    void OnMouseOver();
};