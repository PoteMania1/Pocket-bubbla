#include "Puntos.h"

Puntos::Puntos()
{
	_puntos = 0;
}

int Puntos::getPuntos() const
{
	return _puntos;
}

void Puntos::sumPuntos(int sum)
{
	_puntos += sum;
}

void Puntos::setPuntos(int puntos)
{
	_puntos = puntos;
}


void Puntos::Update()
{
}

Puntos::~Puntos()
{
}


void Puntos::setPuntosHud(int& puntos)
{
	puntos = _puntos;
	std::cout << _puntos << "\n";
}