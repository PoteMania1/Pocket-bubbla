#include <stdlib.h>
#include "Item.h"

Item::Item()
{
	_texture.loadFromFile("Assets/Item/Fruti.png");
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height/2);
	respawn();
}

void Item::update()
{
}

void Item::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

void Item::respawn()
{
	_sprite.setPosition(std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height);
}

sf::FloatRect Item::getBounds() const
{
	return _sprite.getGlobalBounds();
}

sf::Sprite Item::getsprite() const
{
	return _sprite;
}
