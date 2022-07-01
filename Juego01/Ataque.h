#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"
//#include "Personaje.h"
#include "Enemigo.h"
#include "Obstaculo.h"

enum ESTADOS_ATAQUE {
	NOACTIVO,
	ACTIVO
};

class Ataque: public sf::Drawable, public colisionable, public sf::Transformable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	float _frame;
	ESTADOS_ATAQUE _estados;
	//Personaje _p;
	float _velocity;
	float _duracion;
	sf::Vector2f _direccion;
	float _inicioX;
	float _inicioY;
	sf::Clock clock_duracion;
	bool isAlive;
	bool _dir;
public: 
	Ataque();
	Ataque(float inicioX,float inicioY);
	void cmd();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	sf::FloatRect getBounds() const override;
	sf::Sprite getsprite() const;
	ESTADOS_ATAQUE getEstado();
	sf::Sprite setSprite();
	void CargarVecAtacs(sf::Sprite* v, int Fx);
	bool eliminar();
	void setIsAlive(bool x);
	bool getIsAlive();
	void setDir(bool dir);
	bool getDir();
};

