#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"
#include "Personaje.h"
#include "Enemigo.h"
#include "Obstaculo.h"

enum ESTADOS_ATAQUE {
	ACTIVO
};

class Ataque: public sf::Drawable, public colisionable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	float _frame;
	ESTADOS_ATAQUE _estados;
public:
	Ataque();
	void cmd();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	sf::FloatRect getBounds() const override;
	sf::Sprite getsprite() const;
	ESTADOS_ATAQUE getestado();

};

