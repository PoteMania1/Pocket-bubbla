#pragma once
#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Item.h"
#include "Nivel.h"
#include "Obstaculo.h"
#include "Enemigo.h"


class GamePlay : public sf::Drawable
{
private:
	Personaje p;
	Item it;
	Nivel Ni;
	Obstaculo obst;
	sf::Sprite obstFinal[25];
	sf::Vector2f posprev;
	int x;
	Enemigo enemy;
	//Enemigo enemy[5];   ///MUCHOS WARGREYMONES

public:
	GamePlay();
	void cmd();
	sf::Sprite getSprite1();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void setx(int);
	int getx();
};

