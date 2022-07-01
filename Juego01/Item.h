#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"


class Item: public sf::Drawable,public colisionable, public sf::Transformable
{
private:
	sf::Sprite _sprite;
	sf::Sprite _sprites[10];

	sf::Texture _texture;
public:
	Item();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void respawn();
	void respawn2();
	sf::FloatRect getBounds() const override;
	sf::Sprite getsprite() const;
	void CargarVector(sf::Sprite *sprite,int tam);
};

