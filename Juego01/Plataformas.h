#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"
class Plataforma//: public colisionable
{
private:
	sf::RectangleShape _Plataforma[4];

public:
	Plataforma();
	

	sf::RectangleShape& getShape(int x);

	void cmd();
	void update();
	sf::RectangleShape& getDraw(int x);
	//sf::Vector2f getposition1() const;


};

