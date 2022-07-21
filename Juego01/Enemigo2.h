#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Colisionable.h"
#include "Personaje.h"
#include "Ataque.h"

class Enemigo2: public sf::Drawable, public colisionable, public sf::Transformable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	//ESTADOS_ENEMIGO _estado;
	//float _velocidadSalto;
	float _frame;
	sf::Vector2f _velocity;
	sf::Vector2f _posicionInicial;
	bool _estadoVida;


public:
	Enemigo2();
	Enemigo2(int num);
	int auxMovEnemy;
	void cmd(sf::Vector2f positionActual, int cant);
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	sf::FloatRect getBounds() const override;
	sf::Sprite getsprite() const;
	bool getEstadoVida();
	void setEstadoVida(bool vida);
	void setposition(sf::Vector2f pos);
	sf::Vector2f _newPosition;
	int _timeRespawn;
	void respawn();
	sf::Vector2f getPosicionInicial() const;
	sf::Vector2f getposition() const;

};

