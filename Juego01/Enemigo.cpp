#include "Enemigo.h"

Enemigo::Enemigo()
{
		_texture.loadFromFile("Assets/Enemigo/Bicho.png");
		_sprite.setTexture(_texture);
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
		_sprite.setTextureRect({ 0,0,84,63 });
		respawn();
		_frame = 0;
		_estadoVida = true;
}

Enemigo::Enemigo(int num)
{
		_texture.loadFromFile("Assets/Enemigo/Bicho.png");
		_sprite.setTexture(_texture);
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
		_sprite.setTextureRect({ 0,0,84,63 });
		respawn();
		_frame = 0;
		_estadoVida = true;
}

void Enemigo::update()
{	
	_timeRespawn--;

	if (_timeRespawn < 0) {
		_timeRespawn = 60 * 1;
		_newPosition = { std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height };
	}
	if (_newPosition.x > _sprite.getPosition().x) {
		_sprite.move(3, 0);
		_frame += 0.14;
		if (_frame >= 8) {
			_frame = 0;
		}
		_sprite.setTexture(_texture);
		_sprite.setTextureRect({ 0 + int(_frame) * 84,0,84,63 });
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
		_sprite.setScale(1, 1);
	}
	if (_newPosition.x < _sprite.getPosition().x) {
		_sprite.move(-3, 0);
		_frame += 0.14;
		if (_frame >= 5) {
			_frame = 0;
		}
		_sprite.setTexture(_texture);
		_sprite.setTextureRect({ 0 + int(_frame) * 84,0,84,63 });
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
		_sprite.setScale(-1, 1);
	}
	if (_newPosition.y > _sprite.getPosition().y) {
		_sprite.move(0, 3);
		_frame += 0.14;
		if (_frame >= 5) {
			_frame = 0;
		}
		_sprite.setTexture(_texture);
		_sprite.setTextureRect({ 0 + int(_frame) * 84,0,84,63 });
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
		_sprite.setScale(1, 1);
	}
	if (_newPosition.y < _sprite.getPosition().y) {
		_sprite.move(0, -3);
		_frame += 0.14;
		if (_frame >= 5) {
			_frame = 0;
		}
		_sprite.setTexture(_texture);
		_sprite.setTextureRect({ 0 + int(_frame) * 84,0,84,63 });
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
		_sprite.setScale(-1, 1);
	}

	//correccion movimiento

	if (std::abs(_newPosition.x - _sprite.getPosition().x) < 5) {
		_sprite.move( _newPosition.x - _sprite.getPosition().x,0);
	}
	if (std::abs(_newPosition.y - _sprite.getPosition().y) < 5) {
		_sprite.move(0, _newPosition.y - _sprite.getPosition().y);
	}

	//colisiones bordes
	if (_sprite.getGlobalBounds().left < 0) {
		_sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);
	}
	if (_sprite.getGlobalBounds().top < 0) {
		_sprite.setPosition(_sprite.getPosition().x, _sprite.getOrigin().y);
	}
	if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800) {
		_sprite.setPosition(800 - (_sprite.getGlobalBounds().width - _sprite.getOrigin().x), _sprite.getPosition().y);
	}
	if (_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 590) {
		_sprite.setPosition(_sprite.getPosition().x, 590 + (_sprite.getGlobalBounds().height - _sprite.getOrigin().y));
	}
}
void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (_estadoVida) {
		target.draw(_sprite, states);
	}
}

void Enemigo::respawn()
{
	_sprite.setPosition(std::rand() % 600 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height);
	_timeRespawn = 60 * 2;
}

sf::Vector2f Enemigo::getposition() const
{
	return _sprite.getPosition();
}

sf::FloatRect Enemigo::getBounds() const
{
	return _sprite.getGlobalBounds();
}

sf::Sprite Enemigo::getsprite() const
{
	return _sprite;
}

bool Enemigo::getEstadoVida()
{
	return _estadoVida;
}

void Enemigo::setEstadoVida(bool vida)
{
	_estadoVida = vida;
}

void Enemigo::setposition(sf::Vector2f pos)
{
	_sprite.setPosition(pos);
}
