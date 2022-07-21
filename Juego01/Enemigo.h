#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Colisionable.h"

class Enemigo : public sf::Drawable, public colisionable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	float _frame;
	bool _estadoVida;

public:
	Enemigo();
	Enemigo(int num);
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void respawn();
	sf::Vector2f getposition() const;
	sf::FloatRect getBounds() const override;
	sf::Sprite getsprite() const;
	bool getEstadoVida();
	void setEstadoVida(bool vida);
	void setposition(sf::Vector2f pos);
	sf::Vector2f _newPosition;
	int _timeRespawn;
};

