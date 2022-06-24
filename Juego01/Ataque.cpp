#include "Ataque.h"

Ataque::Ataque()
{
	_texture.loadFromFile("Assets/Ataque/hadouken.png");
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	_sprite.setTextureRect({ 0,0,32,32 });
	_frame = 0;
	_estados = NOACTIVO;
	_velocity = { 0,0 };
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
	_sprite.setPosition(_p.cargarPosition());
	switch (_estados)
	{
		//NEW
	case ACTIVO:
		_frame += 0.1;
		if (_frame >= 7) {
			_frame = 0;
		}
		_sprite.setTexture(_texture);
		_sprite.setTextureRect({ 0 + int(_frame) * 32,0,32,32 });
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
		_sprite.move(0, 0);

		break;
	}
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

/*void Ataque::CargarAtaque(sf::Sprite* poder, int fila)
{
	poder[0] = _sprite;
}*/
