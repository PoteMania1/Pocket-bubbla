#include "Ataque.h"
#include <iostream>

Ataque::Ataque()
{
}

Ataque::Ataque(float inicioX,float inicioY)
{
	this->_duracion = 5;
	this->_velocity = 2;
	this->_direccion = { 0,0 };
	this->_inicioX = inicioX;
	this->_inicioY = inicioY;
	this->isAlive = true;
	this->_frame = 0;
	this->_estados = NOACTIVO;

		
	setIsAlive(true);
	_frame = 0;
	_estados = NOACTIVO;
	if (!_texture.loadFromFile("Assets/Ataque/hadouken.png")) {
		std::cout << "a" << "\n";
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
	_sprite.setTextureRect({ 0,0,32,32 });
	_sprite.setPosition(_inicioX-95,_inicioY);
}

void Ataque::cmd()
{
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		_estados = ESTADOS_ATAQUE::ACTIVO;
		_sprite.setPosition(_p.getPreviousPos());
		_velocity.x = 1;
		_sprite.move(_velocity);
	}
	else
	{
		_estados = ESTADOS_ATAQUE::NOACTIVO;
	}*/
}

void Ataque::update()
{
	//_sprite.setPosition(_p.cargarPosition());
	switch (_estados)
	{
		//NEW
	case ACTIVO:

		break;
	}
	//std::cout << getDir() << "\n";

		if (_dir) {
			/*_frame += 0.1;
			if (_frame >= 7) {
				_frame = 0;
			}*/
			_sprite.setTexture(_texture);
			_sprite.setTextureRect({ 0 + int(_frame) * 32,0,32,32 });
			_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
			_sprite.setScale(-1, 1);
			_sprite.move(-_velocity, 0);
		}
		else {
			/*_frame += 0.1;
			if (_frame >= 7) {
				_frame = 0;
			}*/
			_sprite.setTexture(_texture);
			_sprite.setTextureRect({ 0 + int(_frame) * 32,0,32,32 });
			_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
			_sprite.setScale(1, 1);
			_sprite.move(_velocity, 0);
		}
		//_sprite.move(_velocity,0);
}

void Ataque::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

sf::FloatRect Ataque::getBounds() const
{
	return _sprite.getGlobalBounds();
}

sf::Sprite Ataque::getsprite() const
{
	return _sprite;
}

ESTADOS_ATAQUE Ataque::getEstado()
{
	return _estados;
}

sf::Sprite Ataque::setSprite()
{
	return _sprite;
}

void Ataque::CargarVecAtacs(sf::Sprite* v, int Fx)
{
	v[0] = _sprite;
	v[1] = _sprite;
	v[2] = _sprite;
}

bool Ataque::eliminar()
{
	if (clock_duracion.getElapsedTime().asSeconds() < _duracion)
	{
		return false;
	}
	else return true;

}

void Ataque::setIsAlive(bool x)
{
	isAlive = x;
}

bool Ataque::getIsAlive()
{
	return isAlive;
}

void Ataque::setDir(bool dir)
{
	_dir = dir;
}

bool Ataque::getDir()
{
	return _dir;
}

