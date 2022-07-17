#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Puntos.h"

class Hud : public sf::Drawable
{
private:
	sf::Sprite Vida;
	sf::Sprite _hud;
	sf::Font _letra;
	sf::Text _puntos;
	Puntos _realpuntos;
	int _realespuntos;
public:
	Hud();

	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void setPuntos(int puntos);
	void Update();
};

