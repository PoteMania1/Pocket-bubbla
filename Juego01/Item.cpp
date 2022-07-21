#include <stdlib.h>
#include "Item.h"

Item::Item()
{
	_texture1.loadFromFile("Assets/Item/Fruti.png");
	_sprite1.setTexture(_texture1);
	/*for (int i = 0; i < 10; i++) {
		_sprites[i].setTexture(_texture);
	}*/
	_sprite1.setOrigin(_sprite1.getGlobalBounds().width / 2, _sprite1.getGlobalBounds().height/2);
	respawn();
	//_sprite.setPosition(pos);
}

void Item::update()
{
}

void Item::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite1, states);
}

void Item::respawn()
{
	_sprite1.setPosition(std::rand() % 600 + _sprite1.getGlobalBounds().width, std::rand() % 500 + _sprite1.getGlobalBounds().height);
}

/*void Item::respawn2()
{
	for(int i=0;i<10;i++){
		_sprites[i].setPosition(std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height);
	}
}*/

sf::Vector2f Item::getposition() const
{
	return this->getPosition();
}

sf::FloatRect Item::getBounds() const
{
	return _sprite1.getGlobalBounds();
}

sf::Sprite Item::getsprite() const
{
	return _sprite1;
}

void Item::setposition(sf::Vector2f pos)
{
	this->setPosition(pos);
}

/*void Item::CargarVector(sf::Sprite* sprite, const int tam)
{
	for (int i = 0; i < tam; i++) {
		sprite[i] = _sprites[i];
	}
}*/
