#include "Vidas.h"

Vidas::Vidas()
{
	_vidas = 4;
}

void Vidas::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//target.draw(, states);
}

void Vidas::setVidasMenos()
{
	_vidas--;
}

void Vidas::setVidasMas()
{
	_vidas++;
}

int Vidas::getVidas()
{
	return _vidas;
}

void Vidas::Update()
{
}
