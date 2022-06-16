#include "Enemigo.h"

Enemigo::Enemigo()
{
	
		_texture.loadFromFile("Assets/Enemigo/War.png");
		_sprite.setTexture(_texture);
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
		respawn();
	
}

void Enemigo::update()


{	
	_timeRespawn--;

	if (_timeRespawn < 0) {
		_timeRespawn = 60 * 2;
		_newPosition = { std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height };
	}
	if (_newPosition.x > _sprite.getPosition().x) {
		_sprite.move(3, 0);
	}
	if (_newPosition.x < _sprite.getPosition().x) {
		_sprite.move(-3, 0);
	}
	if (_newPosition.y > _sprite.getPosition().y) {
		_sprite.move(0, 3);
	}
	if (_newPosition.y < _sprite.getPosition().y) {
		_sprite.move(0, -3);
	}

	//correccion movimiento

	if (std::abs(_newPosition.x - _sprite.getPosition().x) < 5) {
		_sprite.move( _newPosition.x - _sprite.getPosition().x,0);

	}
	if (std::abs(_newPosition.y - _sprite.getPosition().y) < 5) {
		_sprite.move(0, _newPosition.y - _sprite.getPosition().y);

	}
}
void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

void Enemigo::respawn()
{
	_sprite.setPosition(std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height);
	_timeRespawn = 60 * 2;
}

sf::FloatRect Enemigo::getBounds() const
{
	return _sprite.getGlobalBounds();
}

sf::Sprite Enemigo::getsprite() const
{
	return _sprite;
}
