#include "text.hpp"
#include "ui.hpp"
#include "raylib.h"

Text::Text(Vector2 pos, std::string content)
{
    this->content = content;
}

void Text::Update(float deltaTime)
{
}

void Text::Draw()
{
    if (!active)
        return;

    // Example: draw placeholder text
    DrawTextEx(
        GetFontDefault(), // Use default Raylib font
        "Sample Text",    // The text to display
        position,         // Position
        20.0f,            // Font size
        1.0f,             // Spacing
        BLACK             // Color
    );
}

void Text::OnClick()
{
    // Handle click events
    // You could add code like: printf("Text clicked!\n");
}

void Text::OnMouseOver()
{
    // Handle hover events
}
