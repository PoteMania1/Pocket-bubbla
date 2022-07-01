#include <stdlib.h>
#include "Item.h"

Item::Item()
{
	_texture.loadFromFile("Assets/Item/Fruti.png");
	_sprite.setTexture(_texture);
	for (int i = 0; i < 10; i++) {
		_sprites[i].setTexture(_texture);
	}
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
void Item::respawn2()
{
	for(int i=0;i<10;i++){
		_sprites[i].setPosition(std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height);
	}
}

sf::FloatRect Item::getBounds() const
{
	return _sprite.getGlobalBounds();
}

sf::Sprite Item::getsprite() const
{
	return _sprite;
}

void Item::CargarVector(sf::Sprite *sprite, const int tam)
{
	for (int i = 0; i < tam; i++) {
		sprite[i] = _sprites[i];
	}
}
