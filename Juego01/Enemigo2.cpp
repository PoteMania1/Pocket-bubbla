#include "Enemigo2.h"

Enemigo2::Enemigo2()
{
	_frame = 0;
	_velocity = { 4,4 };
	_texture.loadFromFile("Assets/Enemigo/War.png");
	_sprite.setTexture(_texture);
	//_sprite.setTextureRect({ 0,0,52,45 });
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
	_sprite.setPosition(48, 265);
}

void Enemigo2::cmd(sf::Vector2f positionP)
{
	/*if (_estado == ESTADOS_ENEMIGO::QUIETO) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			_estado = ESTADOS_ENEMIGO::SALTANDO;
			_velocidadSalto = 15;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			_estado = ESTADOS_ENEMIGO::IZQUIERDA;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			_estado = ESTADOS_ENEMIGO::ATAQUE;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			_estado = ESTADOS_ENEMIGO::DERECHA;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			_estado = ESTADOS_ENEMIGO::SALTOIZQ;
			_velocidadSalto = 19;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			_estado = ESTADOS_ENEMIGO::SALTODER;
			_velocidadSalto = 19;
		}
	}*/
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
	target.draw(_sprite, states);
}

sf::FloatRect Enemigo2::getBounds() const
{
	return _sprite.getGlobalBounds();
}

sf::Sprite Enemigo2::getsprite() const
{
	return _sprite;
}
