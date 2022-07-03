#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"
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
	float _velocity;
	float _duracion;
	sf::Vector2f _direccion;
	float _inicioX;
	float _inicioY;
	sf::Clock clock_duracion;
	bool _dir;
public: 
	Ataque();
	Ataque(float inicioX,float inicioY,bool dir);
	void cmd();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	sf::FloatRect getBounds() const override;
	sf::Sprite getsprite() const;
	ESTADOS_ATAQUE getEstado();
	sf::Sprite setSprite();
	bool eliminar();
	void setDir(bool dir);
	bool getDir();
	sf::Vector2f getposition() const;
};

