#pragma once
#include <SFML/Graphics.hpp>


class colisionable {
public:
	virtual sf::FloatRect getBounds() const = 0;
	bool isColision(colisionable& col) const;
};