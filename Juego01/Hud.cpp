#include "Hud.h"

Hud::Hud()
{
	if (!_letra.loadFromFile("Font/Perfect DOS VGA 437.ttf")) {
		std::cout << "No cargo la fuente.";
	}
	_puntos.setFont(_letra);
	_puntos.setPosition(20, 10);
	_puntos.setCharacterSize(20);
	_puntos.setOrigin(_puntos.getGlobalBounds().width / 2,
		_puntos.getGlobalBounds().height / 2);


}

void Hud::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	int xs = 0;
	target.draw(_puntos, states);
}

void Hud::setPuntos(int puntos)
{
	_realespuntos = puntos;
}

void Hud::Update()
{
	_puntos.setString(std::to_string(_realespuntos));
}
