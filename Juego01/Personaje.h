#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Colisionable.h"
#include "Obstaculo.h"

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
	sf::SoundBuffer _bufferPASOS;
	sf::Sound _soundPASOS;
	int _vida;
	int _puntos;
	float _velocidadSalto;
	ESTADOS_PERSONAJE _estado;
	//NEW
	float _frame;
	sf::Vector2f _PreviousPos;
	//bool _caida;
	
public:
	Personaje();
	void cmd();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	sf::FloatRect getBounds() const override;
	sf::Sprite getsprite() const;
	//void LeerTextura(sf::Sprite);
	//int getglobaltop();
	//int getglobal();
	//NEW
	float getposx();
	void quieto(float, float);
	sf::Vector2f getPreviousPos();
	ESTADOS_PERSONAJE getEstado();
	void setEstado(ESTADOS_PERSONAJE);
	sf::FloatRect getGlobalBounds() const;
	sf::Vector2f getposition() const;
	//void setposition(int,int);
	void respawn(sf::Vector2f pos);
	float getvelocidadSalto();
	void pestaniaste();
	void sumandoando();
	void sonidos(ESTADOS_PERSONAJE);
};

