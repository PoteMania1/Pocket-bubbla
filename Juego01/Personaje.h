#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"
#include "Obstaculo.h"
#include "Plataformas.h"

enum ESTADOS_PERSONAJE {
	QUIETO,
	DERECHA,
	IZQUIERDA,
	SALTANDO,
	SALTOIZQ,
	SALTODER,
	ABAJO
};

class Personaje: public sf::Drawable, public colisionable, public sf::Transformable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Sprite _spriteCORRER;
	sf::Texture _textureCORRER;
	sf::Vector2f _velocity;
	float _velocidadSalto;
	ESTADOS_PERSONAJE _estado;
	float _frame;
	//NEW
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
	void move(float x, float y);
	sf::FloatRect getGlobalBounds() const;
	sf::Vector2f getposition() const;
	//void setposition(int,int);
	void respawn(sf::Vector2f pos);
	float getvelocidadSalto();
};
