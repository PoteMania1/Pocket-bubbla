#pragma once
#include <SFML/Graphics.hpp>

class GamePlayable
{
public:
    virtual void createBala(float positionX, float positionY, bool izqOder) = 0;
};