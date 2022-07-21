#include "Enemigo2.h"

Enemigo2::Enemigo2()
{
	_frame = 0;
	_velocity = { 1,0 };
	_texture.loadFromFile("Assets/Enemigo/War.png");
	_sprite.setTexture(_texture);
	//_sprite.setTextureRect({ 0,0,52,45 });
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
	_sprite.setPosition(170, 287);
	_posicionInicial = _sprite.getPosition();
	auxMovEnemy = 0;
	_estadoVida = true;
}

Enemigo2::Enemigo2(int num)
{
	_frame = 0;
	_velocity = { 1,0 };
	_texture.loadFromFile("Assets/Enemigo/War.png");
	_sprite.setTexture(_texture);
	//_sprite.setTextureRect({ 0,0,52,45 });
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
	_sprite.setPosition(5, 381);
	_posicionInicial = _sprite.getPosition();
	auxMovEnemy = 0;
	_estadoVida = true;
}

void Enemigo2::cmd(sf::Vector2f positionActual,int cant)
{
	if (_posicionInicial.x - positionActual.x <= 0
		&& auxMovEnemy == 0) {
		_sprite.setScale(-1, 1);
		_sprite.move(-_velocity);
		//std::cout << _posicionInicial.x - positionActual.x<<"\n";
	}
	else if (_posicionInicial.x - positionActual.x >= -cant) {
		auxMovEnemy = 1;
	}
	else if (_posicionInicial.x - positionActual.x >= -cant
		&& auxMovEnemy == 1) {
		_sprite.setScale(1, 1);
		_sprite.move(_velocity);
		//std::cout << "derecha\n";
	}
	else if (_posicionInicial.x - positionActual.x <= 0) {
			auxMovEnemy = 0;
	}
}

void Enemigo2::update()
{
	_timeRespawn--;

	if (_timeRespawn < 0) {
		_timeRespawn = 60 * 1;
		_newPosition = { std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height };
	}
	if (_newPosition.x > _sprite.getPosition().x) {
		_sprite.move(3, 0);
		_sprite.setTexture(_texture);
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
		_sprite.setScale(1, 1);
	}
}

void Enemigo2::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (_estadoVida) {
		target.draw(_sprite, states);
	}
}

sf::FloatRect Enemigo2::getBounds() const
{
	return _sprite.getGlobalBounds();
}

sf::Sprite Enemigo2::getsprite() const
{
	return _sprite;
}

bool Enemigo2::getEstadoVida()
{
	return _estadoVida;
}

void Enemigo2::setEstadoVida(bool vida)
{
	_estadoVida = vida;
}

void Enemigo2::setposition(sf::Vector2f pos)
{
	_sprite.setPosition(pos);
}

void Enemigo2::respawn()
{
	_sprite.setPosition(std::rand() % 600 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height);
}

sf::Vector2f Enemigo2::getPosicionInicial() const
{
	return _posicionInicial;
}

sf::Vector2f Enemigo2::getposition() const
{
	return _sprite.getPosition();
}
