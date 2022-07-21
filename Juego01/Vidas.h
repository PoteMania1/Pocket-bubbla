#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Vidas : public sf::Drawable
{
private:
	int _vidas;
	sf::Texture _sumvidasT;
	sf::Sprite _sumvidas;
public:
	Vidas();

	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void setVidasMenos();
	void setVidasMas();
	void setvida(int vida);
	int getVidas();
	void Update();

};

