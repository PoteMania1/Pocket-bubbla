#include "Personaje.h"
#include <iostream>

Personaje::Personaje(GamePlayable& gameplay)  :_gameplay(gameplay) {
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
	_sprite.setPosition(300, 565);
	_velocidadSalto = 0;
	_estado = ESTADOS_PERSONAJE::QUIETO;
	_vida = 4;
	_puntos = 0;
	_textureATAQUE.loadFromFile("Assets/Personaje/Ash-Ataque.png");
	_spriteATAQUE.setTexture(_textureATAQUE);
	_spriteATAQUE.setTextureRect({ 0,0,42,37 });
	_spriteATAQUE.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
	_bufferPasos.loadFromFile("Sounds/Ash/Pasos.wav");
	_bufferAtaque.loadFromFile("Sounds/Ash/Ataque.wav");
	_bufferSalto1.loadFromFile("Sounds/Ash/Salto1.wav");
	inicioJuego = 0;
	_cooldown = 0;
	_estadoVida = true;
}


void Personaje::cmd()
{
	//comandos del personaje
	if (_estado == ESTADOS_PERSONAJE::QUIETO && _estadoVida) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			_estado = ESTADOS_PERSONAJE::SALTANDO;
			_velocidadSalto = 15;
			_sound.setBuffer(_bufferSalto1);
			sonidos();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			_estado = ESTADOS_PERSONAJE::IZQUIERDA;
			_sound.setBuffer(_bufferPasos);
			//sonidos();
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			_estado = ESTADOS_PERSONAJE::DERECHA;
			_sound.setBuffer(_bufferPasos);
			//sonidos();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			_estado = ESTADOS_PERSONAJE::ATAQUE;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			_estado = ESTADOS_PERSONAJE::SALTOIZQ;
			_velocidadSalto = 19;
			_sound.setBuffer(_bufferSalto1);
			sonidos();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			_estado = ESTADOS_PERSONAJE::SALTODER;
			_velocidadSalto = 19;
			_sound.setBuffer(_bufferSalto1);
			sonidos();
		}
	}
}


void Personaje::update() {

	if (!_estadoVida) {
		_estadoVida = true;
		_sprite.setPosition(0, 472);
		if (_vida<0) {
			_sprite.setPosition(0, 472);
		}
	}

	//Aplica gravedad al personaje para que no quede flotando al iniciar el juego
	if (inicioJuego == 0){
		_velocidadSalto = -5;
		inicioJuego++;
	}
	//Cooldown de ataque, para no spamear
	if (_cooldown > 0) {
		_cooldown--;
	}

	_PreviousPos = _sprite.getPosition();
	
	if (_velocidadSalto < -5) {
		_velocidadSalto = -5;
	}

	//movimiento personaje
	switch (_estado)
	{
		//NEW
	case QUIETO:

		_frame += 0.14;
		if (_frame >= 4) {
			_frame = 0;
		}
		_sprite.setTexture(_texture);
		_sprite.setTextureRect({ 0 + int(_frame) * 30,0,30,41 });
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
		_sprite.move(0, -_velocidadSalto);

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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&& _cooldown <= 0) {
			disparar(this->getposition().x, this->getposition().y, getscale());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			_sprite.setScale(1, 1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			_sprite.setScale(-1, 1); 
		}

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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && _cooldown <= 0) {
			disparar(this->getposition().x, this->getposition().y, getscale());
		}

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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && _cooldown <= 0) {
			disparar(this->getposition().x, this->getposition().y, getscale());
		}

		break;
	case IZQUIERDA:

		_frame += 0.25;
		if (_frame >= 8) {
			_frame = 0;
		}
		_sprite.setTexture(_textureCORRER);
		_sprite.setTextureRect({ 0 + int(_frame) * 43,0,42,37 });
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
		_velocity.x = -3;
		_sprite.move(_velocity.x, -_velocidadSalto);
		_sprite.setScale(-1, 1);

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
		_sprite.move(_velocity.x, -_velocidadSalto);
		_sprite.setScale(1, 1);

		_estado = ESTADOS_PERSONAJE::QUIETO;
		break;

	case ATAQUE:

		/*/_frame += 0.25;
		if (_frame >= 3) {
			_frame = 0;
		}*/
		_sprite.setTexture(_textureATAQUE);
		_sprite.setTextureRect({ /*(int(_frame) * 44) + */ 220,0,44,37});
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
		_sprite.move(0, -_velocidadSalto);
		if(_cooldown <= 0){
			disparar(this->getposition().x, this->getposition().y,getscale());
		}

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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && _cooldown <= 0) {
			disparar(this->getposition().x, this->getposition().y, getscale());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			_sprite.setScale(1, 1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			_sprite.setScale(-1, 1);
		}
		break;
	}

	//colisiones piso
	if (_sprite.getGlobalBounds().left < 0) {
		_sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);
	}
	if (_sprite.getGlobalBounds().top < 45) {
		_sprite.setPosition(_sprite.getPosition().x, _sprite.getOrigin().y+45);
	}
	if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800) {
		_sprite.setPosition(800 - (_sprite.getGlobalBounds().width - _sprite.getOrigin().x), _sprite.getPosition().y);
	}
	if (_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 590) {
		_sprite.setPosition(_sprite.getPosition().x, 590 + (_sprite.getGlobalBounds().height - _sprite.getOrigin().y));
		_estado = ESTADOS_PERSONAJE::QUIETO;
	}
	//colisiones obst
	
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

sf::Vector2f Personaje::getPreviousPos()
{
	return _PreviousPos;
}

ESTADOS_PERSONAJE Personaje::getEstado()
{
	return _estado;
}

void Personaje::setEstado(ESTADOS_PERSONAJE estado)
{
	_estado = estado;
}

void Personaje::setEstadoVida(bool vida)
{
	_estadoVida = vida;
}

sf::FloatRect Personaje::getGlobalBounds() const
{
	return _sprite.getGlobalBounds();
}

sf::Vector2f Personaje::getposition() const
{
	return _sprite.getPosition();
}

sf::Vector2f Personaje::getscale()
{
	return _sprite.getScale();
}

void Personaje::respawn(sf::Vector2f pos)
{
	if(_velocidadSalto < 0){
		_estado = ESTADOS_PERSONAJE::QUIETO;
		_sprite.setPosition(_sprite.getPosition().x, pos.y+2 + (_sprite.getGlobalBounds().height - _sprite.getOrigin().y));
	}
}

void Personaje::setVidasMenos()
{
	if (_vida >= 1) {
		_vida --;
		std::cout <<"Vida: " << _vida << std::endl;
	}
}

void Personaje::setVidasMas() {
	if (_vida <= 3) {
		_vida ++;
		std::cout << "Vida: " << _vida << std::endl;
	}
}

void Personaje::sonidos()
{
	if (_sound.getStatus() != sf::SoundSource::Status::Playing) {
		_sound.play();
	}
	else {
		_sound.stop();
	}
}


void Personaje::disparar(float positionX, float positionY,sf::Vector2f scale) {

	bool izq;
	if (scale.x == -1) {
		izq = true;
		positionX += 25;
		positionY -= 5;
		getCurrentGamePlay().createBala(positionX, positionY, izq);
		_cooldown = 10;
	}
	else {
		izq = false;
		positionX += 25;
		positionY -= 5;
		getCurrentGamePlay().createBala(positionX,positionY,izq);
		_cooldown = 10;
	}
}

GamePlayable& Personaje::getCurrentGamePlay()
{
	return _gameplay;
}