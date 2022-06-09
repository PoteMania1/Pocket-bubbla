#include "Plataformas.h"



Plataforma::Plataforma()
{
	_Plataforma[0].setSize({200,20});
	_Plataforma[1].setSize({200,20});
	_Plataforma[2].setSize({200,20});
	_Plataforma[3].setSize({200,20});
	_Plataforma[0].setFillColor(sf::Color::Green);
	_Plataforma[1].setFillColor(sf::Color::Green);
	_Plataforma[2].setFillColor(sf::Color::Green);
	_Plataforma[3].setFillColor(sf::Color::Green);
	_Plataforma[0].setPosition(300, 600);
	_Plataforma[1].setPosition(200, 600);
	_Plataforma[2].setPosition(400, 600);
	_Plataforma[3].setPosition(500, 600);
}

sf::RectangleShape& Plataforma::getShape(int x)
{
	return _Plataforma[x];
}
 
void Plataforma::cmd()
{
}

void Plataforma::update()
{
}

sf::RectangleShape& Plataforma::getDraw(int x)
{
	return _Plataforma[x];
}


