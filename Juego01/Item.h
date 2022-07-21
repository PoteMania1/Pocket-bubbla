#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"


class Item: public sf::Drawable,public colisionable, public sf::Transformable
{
private:
	sf::Texture _texture1;
	sf::Sprite _sprite1;
	sf::Texture _texture2;
	sf::Sprite _sprite2;
	sf::Texture _texture3;
	sf::Sprite _sprite3;
	sf::Texture _texture4;
	sf::Sprite _sprite4;
	sf::Texture _texture5;
	sf::Sprite _sprite5;
	sf::Texture _texture6;
	sf::Sprite _sprite6;
	sf::Texture _texture7;
	sf::Sprite _sprite7;
	
	//sf::Sprite _sprites[10];

public:
	Item();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void respawn();
	void respawn2();
	sf::Vector2f getposition() const;
	sf::FloatRect getBounds() const override;
	sf::Sprite getsprite() const;
	void CargarVector(sf::Sprite *sprite,int tam);
	void setposition(sf::Vector2f pos);
};

