#include "Hud.h"

Hud::Hud()
{
	if (!_letra.loadFromFile("Font/Perfect DOS VGA 437.ttf")) {
		std::cout << "No cargo la fuente.";
	}
	_puntos.setFont(_letra);
	_puntos.setPosition(378, 9);
	_puntos.setCharacterSize(20);
	_puntos.setOrigin(_puntos.getGlobalBounds().width / 2,
		_puntos.getGlobalBounds().height / 2);


	_vidaT.loadFromFile("Assets/Hud/Corazones-4.png");
	 _sinVidaT.loadFromFile("Assets/Hud/Corazones-Vacios.png");
	 _hudT.loadFromFile("Assets/Hud/CajaAsh.png");
	 _ashT.loadFromFile("Assets/Hud/Ash.png");
	 _puntosHUDT.loadFromFile("Assets/Hud/Puntos.png");
	 _fondoT.loadFromFile("Assets/Hud/Hud-Fondo.png");

	 _vida.setTexture(_vidaT);
	 _sinVida.setTexture(_sinVidaT);
	 _hud.setTexture(_hudT);
	 _ash.setTexture(_ashT);
	 _puntosHUD.setTexture(_puntosHUDT);
	 _fondo.setTexture(_fondoT);

	 _vida.setPosition(60, 12);
	 _vida.setScale(2, 2);
	 _sinVida.setPosition(60, 12);
	 _sinVida.setScale(2, 2);
	 _hud.setPosition(3, 3);
	 _ash.setPosition(8, 8);
	 _puntosHUD.setPosition(400, 22);
	 _puntosHUD.setOrigin(_puntosHUD.getGlobalBounds().width / 2,
		 _puntosHUD.getGlobalBounds().height / 2);
	 _puntosHUD.setScale(1.5f, 1.5f);
	 _fondo.setPosition(0, 0);
	 
}

void Hud::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_fondo, states);
	target.draw(_hud, states);
	target.draw(_ash, states);
	target.draw(_sinVida, states);
	target.draw(_vida, states);
	target.draw(_puntosHUD, states);
	target.draw(_puntos, states);
}

void Hud::setPuntos(int puntos)
{
	_realpuntos = puntos;
}

void Hud::setVidas(int vidas)
{
	_realvidas = vidas;
}

void Hud::setSpriteVidas()
{
	if (_realvidas == 4) {
		_vidaT.loadFromFile("Assets/Hud/Corazones-4.png");
	}
	else if (_realvidas == 3) {
		_vidaT.loadFromFile("Assets/Hud/Corazones-3.png");
	}
	else if (_realvidas == 2) {
		_vidaT.loadFromFile("Assets/Hud/Corazones-2.png");
	}
	else if (_realvidas == 1) {
		_vidaT.loadFromFile("Assets/Hud/Corazones-1.png");
	}
}

void Hud::Update()
{
	_puntos.setString(std::to_string(_realpuntos));
	setSpriteVidas();
}

/*std::string Hud::toString() {
	std::string result;
	result ="Puntos: " + std::to_string(_realpuntos) + "| Vidas: " + std::to_string(_realvidas);
	return result;
}

bool Hud::LeerDeDisco(int nroRegistro)
{
	FILE* p = fopen("Score.dat", "rb");
	if (p == NULL) {
		return false;
	}
	fseek(p, nroRegistro * sizeof(Hud), SEEK_SET);
	bool ok = fread(this, sizeof(Hud), 1, p);
	fclose(p);
	return ok;
}

bool Hud::GuardarEnDisco(int nroRegistro)
{
	FILE* p = fopen("Score.dat", "rb+");
	if (p == NULL) {
		return false;
	}
	fseek(p, nroRegistro * sizeof(Hud), SEEK_SET);
	bool guardo = fwrite(this, sizeof(Hud), 1, p);
	fclose(p);
	return guardo;
}*/
