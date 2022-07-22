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
	std::cout << _puntos << "\n";
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

std::string Puntos::toString() {
	std::string result;
	result = "Puntos: " + std::to_string(_puntos);
	return result;
}

bool Puntos::LeerDeDisco(int nroRegistro)
{
	FILE* p = fopen("Score.dat", "rb");
	if (p == NULL) {
		return false;
	}
	fseek(p, nroRegistro * sizeof(Puntos), SEEK_SET);
	bool ok = fread(this, sizeof(Puntos), 1, p);
	std::cout << "Leido bro\n";
	fclose(p);
	return ok;
}

bool Puntos::GuardarEnDisco()
{
	FILE* p = fopen("Score.dat", "ab");
	if (p == NULL) {
		return false;
	}
	bool guardo = fwrite(this, sizeof(Puntos), 1, p);
	fclose(p);
	std::cout << _puntos << "\n";
	std::cout << "Guardado bro\n";
	return guardo;
}