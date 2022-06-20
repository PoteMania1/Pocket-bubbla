#pragma once
#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Item.h"
#include "Nivel.h"
#include "Obstaculo.h"
#include "Enemigo.h"
#include "Ataque.h"

class GamePlay : public sf::Drawable
{
private:
	Personaje _ash;
	Item _fruta;
	Nivel _nivel1;
	Obstaculo _plataforma;
	Ataque _hadouken;
	sf::Sprite _plataformaD[25];
	sf::Vector2f posprev;
	int x;
	Enemigo _enemy;
	bool _colision;
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

