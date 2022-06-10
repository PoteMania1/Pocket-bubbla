#pragma once
#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Item.h"
#include "Nivel.h"
#include "Obstaculo.h"
#include "Plataformas.h"


class GamePlay: public sf::Drawable
{
private:
	Personaje p;
	Item it;
	Nivel Ni;
	Obstaculo obst;
	sf::Vector2f posprev;
	Plataforma* vplataforma;
	int cantPlataformas;
	Plataforma* _Plataforma;
	int x;

public:
	GamePlay(int);
	GamePlay();
	void cmd();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void setx(int);
	int getx();
	
};

