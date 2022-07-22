#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Puntos
{
private:
	int _puntos;

public:
	Puntos();
	int getPuntos() const;
	void sumPuntos(int sum);
	void setPuntos(int puntos);
	void setPuntosHud(int &puntos);
	void Update();
	std::string toString();
	bool LeerDeDisco(int nroRegistro);
	bool GuardarEnDisco();
	~Puntos();
};

