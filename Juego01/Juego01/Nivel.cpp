#include "Nivel.h"

Nivel::Nivel()
{
	_texture.loadFromFile("Assets/Nivel/Fondo2.png");
	_fondo.setTexture(_texture);

	
}

void Nivel::update()
{
}

void Nivel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_fondo, states);
}


sf::Sprite Nivel::getfondo() const
{
	return _fondo;
}

sf::FloatRect Nivel::getBounds() const
{
	return _fondo.getGlobalBounds();
}

