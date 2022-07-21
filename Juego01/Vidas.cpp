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
	if (_vidas >= 1) {
		_vidas--;
	}
}

void Vidas::setVidasMas()
{
	if (_vidas <= 3) {
		_vidas++;
	}
}

void Vidas::setvida(int vida)
{
	_vidas = vida;
}

int Vidas::getVidas()
{
	return _vidas;
}

void Vidas::Update()
{
}
