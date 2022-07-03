#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Colisionable.h"
#include "Obstaculo.h"
#include "Personaje.h"
#include "Ataque.h"

/*enum ESTADOS_ENEMIGO {
	QUIETO,
	DERECHA,
	IZQUIERDA,
	SALTANDO,
	SALTOIZQ,
	SALTODER,
	ABAJO,
	ATAQUE,
	CAYENDO
};*/

class Enemigo2: public sf::Drawable, public colisionable, public sf::Transformable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	//ESTADOS_ENEMIGO _estado;
	//float _velocidadSalto;
	float _frame;
	sf::Vector2f _velocity;
public:
	Enemigo2();
	void cmd(sf::Vector2f positionP);
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	sf::FloatRect getBounds() const override;
	sf::Sprite getsprite() const;
	sf::Vector2f _newPosition;
	int _timeRespawn;
	void respawn();
};

