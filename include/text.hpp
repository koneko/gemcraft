#pragma once
#include "ui.hpp"
#include <string>

class Text : public UI
{
public:
    Vector2 position{0, 0};
    std::string content;
    float rotation = 0.0f;
    int zIndex;
    bool active = true;

    Text(Vector2 pos, std::string content);

    void Update(float deltaTime);

    void Draw();

    void OnClick();

    void OnMouseOver();
};