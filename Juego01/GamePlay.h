#pragma once
#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Item.h"
#include "Nivel.h"
#include "Obstaculo.h"


class GamePlay: public sf::Drawable
{
private:
	Personaje p;
	Item it;
	Nivel Ni;
	Obstaculo obst[10];
	sf::Vector2f posprev;
	int x;
	

public:
	GamePlay();
	void cmd();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void setx(int);
	int getx();
	
};

