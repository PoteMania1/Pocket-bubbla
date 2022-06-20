#include "Personaje.h"
#include <iostream>

Personaje::Personaje() {
	_frame = 0;
	_velocity = { 4,4 };
	_texture.loadFromFile("Assets/Personaje/Ash-DePie.png");
	_sprite.setTexture(_texture);
	_sprite.setTextureRect({ 0,0,30,41});
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
	_textureCORRER.loadFromFile("Assets/Personaje/Ash-Corriendo.png");
	_spriteCORRER.setTexture(_textureCORRER);
	_spriteCORRER.setTextureRect({ 0,0,42,37 });
	_spriteCORRER.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
	_textureSALTANDO.loadFromFile("Assets/Personaje/Ash-Salto-38x422.png");
	_spriteSALTANDO.setTexture(_textureSALTANDO);
	_spriteSALTANDO.setTextureRect({ 0,0,42,37 });
	_spriteSALTANDO.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
	_sprite.setPosition(300, 600);
	_velocidadSalto = 0;
	_estado = ESTADOS_PERSONAJE::QUIETO;
	_vida = 3;
	_puntos = 0;
	_textureATAQUE.loadFromFile("Assets/Personaje/Ash-Ataque.png");
	_spriteATAQUE.setTexture(_textureATAQUE);
	_spriteATAQUE.setTextureRect({ 0,0,42,37 });
	_spriteATAQUE.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
}


void Personaje::cmd()
{
	//comandos del personaje
	if (_estado == ESTADOS_PERSONAJE::QUIETO) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			_estado = ESTADOS_PERSONAJE::SALTANDO;
			_velocidadSalto = 15;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			_estado = ESTADOS_PERSONAJE::IZQUIERDA;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			_estado = ESTADOS_PERSONAJE::ATAQUE;
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			_estado = ESTADOS_PERSONAJE::DERECHA;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			_estado = ESTADOS_PERSONAJE::SALTOIZQ;
			_velocidadSalto = 19;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			_estado = ESTADOS_PERSONAJE::SALTODER;
			_velocidadSalto = 19;
		}
	}
}


void Personaje::update() {

	_PreviousPos = _sprite.getPosition();
	
	if (_velocidadSalto < -5) {
		_velocidadSalto = -5;
	}
	//movimiento personaje
		//_velocity.x = _velocity.y = 0;
	switch (_estado)
	{
		//NEW
	case QUIETO:
		_frame += 0.14;
		//_velocidadSalto -= 2;
		if (_frame >= 4) {
			_frame = 0;
		}
		_sprite.setTexture(_texture);
		_sprite.setTextureRect({ 0 + int(_frame) * 30,0,30,41 });
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
		_sprite.move(0, -_velocidadSalto);
		//_velocidadSalto += 2;
		break;
	case SALTANDO:
		_velocidadSalto -= 1;
		_sprite.move(0, -_velocidadSalto);
		_frame += 0.080;
		if (_frame >= 4) {
			_frame = 0;
		}
		_sprite.setTexture(_textureSALTANDO);
		_sprite.setTextureRect({ 0 + int(_frame) * 38,0,38,42 });
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
		break;
	case SALTOIZQ:
		_velocidadSalto -= 1;
		_sprite.move(-3, -_velocidadSalto);
		_velocity.x = -1;
		_sprite.move(_velocity);
		_frame += 0.080;
		if (_frame >= 4) {
			_frame = 0;
		}
		_sprite.setTexture(_textureSALTANDO);
		_sprite.setTextureRect({ 0 + int(_frame) * 38,0,38,42 });
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
		_sprite.setScale(-1, 1);
		break;
	case SALTODER:
		_velocidadSalto -= 1;
		_sprite.move(3, -_velocidadSalto);
		_velocity.x = 1;
		_sprite.move(_velocity);
		_frame += 0.080;
		if (_frame >= 4) {
			_frame = 0;
		}
		_sprite.setTexture(_textureSALTANDO);
		_sprite.setTextureRect({ 0 + int(_frame) * 38,0,38,42 });
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
		_sprite.setScale(1, 1);
		break;
	case IZQUIERDA:
		_frame += 0.25;
		if (_frame >= 8) {
			_frame = 0;
		}
		_sprite.setTexture(_textureCORRER);
		_sprite.setTextureRect({ 0 + int(_frame) * 43,0,42,37 });
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
		//_velocity.x = -3;
		//_velocidadSalto -= 2;
		_sprite.move(-3, -_velocidadSalto);
		_sprite.setScale(-1, 1);
		//_velocidadSalto += 2;
		_estado = ESTADOS_PERSONAJE::QUIETO;
		break;
	case DERECHA:
		_frame += 0.25;
		if (_frame >= 8) {
			_frame = 0;
		}
		_sprite.setTexture(_textureCORRER);
		_sprite.setTextureRect({ 0 + int(_frame) * 43,0,42,37 });
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
		_velocity.x = 3;
		//_velocidadSalto -= 2;
		_sprite.move(3, -_velocidadSalto);
		_sprite.setScale(1, 1);
		//_velocidadSalto += 2;
		_estado = ESTADOS_PERSONAJE::QUIETO;
		break;
	case ATAQUE:
		_frame += 0.25;
		//_velocidadSalto -= 2;
		if (_frame >= 8) {
			_frame = 0;
		}
		_sprite.setTexture(_textureATAQUE);
		_sprite.setTextureRect({ 0 + int(_frame) * 44,0,44,37 });
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
		_sprite.move(0, -_velocidadSalto);
		//_velocidadSalto += 2;
		break;
	case CAYENDO:
		_velocidadSalto -= 1;
		_sprite.move(0, -_velocidadSalto);
		_frame += 0.080;
		if (_frame >= 4) {
			_frame = 0;
		}
		_sprite.setTexture(_textureSALTANDO);
		_sprite.setTextureRect({ 0 + int(_frame) * 38,0,38,42 });
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
		_sprite.setScale(1, 1);
		//_estado = ESTADOS_PERSONAJE::QUIETO;
		break;
	}

	//_velocidadSalto -= 1;
	//_velocity.y -= _velocidadSalto;
	//move(_velocity.x, _velocity.y);

	//colisiones piso
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
		_estado = ESTADOS_PERSONAJE::QUIETO;
	} 
	
	
}

//personaje dibujable
void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}


sf::FloatRect Personaje::getBounds() const
{
	return _sprite.getGlobalBounds();
}


sf::Sprite Personaje::getsprite() const
{
	return _sprite;
}

float Personaje::getposx()
{
	return _sprite.getPosition().x;
}

void Personaje::quieto(float x, float y)
{
	_estado = ESTADOS_PERSONAJE::QUIETO;
	_velocidadSalto = 0;
	_sprite.setPosition(x, y);
}

sf::Vector2f Personaje::getPreviousPos()
{
	return _PreviousPos;
}

void Personaje::setEstado(ESTADOS_PERSONAJE estado)
{
	_estado = estado;
}

sf::FloatRect Personaje::getGlobalBounds() const
{
	return _sprite.getGlobalBounds();
}

sf::Vector2f Personaje::getposition() const
{
	return _sprite.getPosition();
}

void Personaje::respawn(sf::Vector2f pos)
{
	if(_velocidadSalto < 0){
		//std::cout << _sprite.getGlobalBounds().top;
		_estado = ESTADOS_PERSONAJE::QUIETO;
		_sprite.setPosition(_sprite.getPosition().x, pos.y+5 + (_sprite.getGlobalBounds().height - _sprite.getOrigin().y));
	}
}

float Personaje::getvelocidadSalto()
{
	return _velocidadSalto;
}

void Personaje::pestaniaste()
{
	_vida -= 1;
	_sprite.setPosition(10, 600);
	std::cout <<"Vida: " << _vida << std::endl;
	if (_vida == 0) {
		_puntos = 0;
		std::cout << "Puntos: " << _puntos << std::endl;
	}
}

void Personaje::sumandoando()
{
	_puntos += 10;
	std::cout <<"Puntos: " << _puntos << std::endl;
	
}

/*void Personaje::setposition(int x, int y)
{
	_sprite.setPosition().x;
}*/


