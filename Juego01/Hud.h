#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Puntos.h"

class Hud : public sf::Drawable
{
private:
	sf::Texture _vidaT;
	sf::Texture _sinVidaT;
	sf::Texture _hudT;
	sf::Texture _ashT;
	sf::Texture _puntosHUDT;
	sf::Texture _fondoT;
	sf::Sprite _vida;
	sf::Sprite _sinVida;
	sf::Sprite _hud;
	sf::Sprite _ash;
	sf::Sprite _puntosHUD;
	sf::Sprite _fondo;

	sf::Font _letra;
	sf::Text _puntos;
	int _realpuntos;
	int _realvidas;
public:
	Hud();

	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void setPuntos(int puntos);
	void setVidas(int vidas);
	void Update();
};

