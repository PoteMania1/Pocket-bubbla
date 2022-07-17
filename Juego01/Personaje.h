#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Colisionable.h"
#include "Ataque.h"
#include "GamePlayable.h"
#include "Puntos.h"

enum ESTADOS_PERSONAJE {
	QUIETO,
	DERECHA,
	IZQUIERDA,
	SALTANDO,
	SALTOIZQ,
	SALTODER,
	ABAJO,
	ATAQUE,
	CAYENDO
};

class Personaje: public sf::Drawable, public colisionable, public sf::Transformable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Sprite _spriteCORRER;
	sf::Texture _textureCORRER;
	sf::Sprite _spriteSALTANDO;
	sf::Texture _textureSALTANDO;
	sf::Sprite _spriteATAQUE;
	sf::Texture _textureATAQUE;
	sf::Vector2f _velocity;
	sf::SoundBuffer _bufferPasos;
	sf::SoundBuffer _bufferAtaque;
	sf::SoundBuffer _bufferSalto1;
	sf::SoundBuffer _bufferSalto2;
	sf::SoundBuffer _bufferSalto3;
	sf::Sound _sound;
	int _vida;
	Puntos _punto;
	int _puntos;
	float _velocidadSalto;
	ESTADOS_PERSONAJE _estado;
	//NEW
	float _frame;
	sf::Vector2f _PreviousPos;
	GamePlayable& _gameplay;
	int _cooldown;
	
public:
	Personaje(GamePlayable& gameplay);
	void cmd();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	sf::FloatRect getBounds() const override;
	sf::Sprite getsprite() const;
	//NEW
	int inicioJuego;
	sf::Vector2f getPreviousPos();
	ESTADOS_PERSONAJE getEstado();
	void setEstado(ESTADOS_PERSONAJE);
	sf::FloatRect getGlobalBounds() const;
	sf::Vector2f getposition() const;
	sf::Vector2f getscale();
	void respawn(sf::Vector2f pos);
	void controladorVida();
	void sumaPuntos();
	void sonidos();
	void disparar(float positionX, float positionY,sf::Vector2f scale);
	GamePlayable& getCurrentGamePlay();
};

