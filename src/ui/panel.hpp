#pragma once
#include <raylib.h>

class Panel
{
public:
    Panel(int x, int y, int width, int height, int zIndex, Image backgroundImage);
    void update();
    void draw();

private:
    int x, y, width, height, zIndex;
    bool isHovered;
    Image backgroundImage;
};