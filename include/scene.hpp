#pragma once

class Scene
{
public:
    virtual ~Scene() = default;
    void virtual load() = 0;
};