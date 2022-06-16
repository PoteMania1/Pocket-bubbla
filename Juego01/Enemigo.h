#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"
class Enemigo : public sf::Drawable, public colisionable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
public:
	Enemigo();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void respawn();
	sf::FloatRect getBounds() const override;
	sf::Sprite getsprite() const;
	sf::Vector2f _newPosition;
	int _timeRespawn;
};

