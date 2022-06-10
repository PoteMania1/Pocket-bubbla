#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"

class Nivel : public sf::Drawable, public colisionable
{
private:
	sf::Sprite _fondo;
	sf::Texture _texture;
	
	int _frame = 0;
public:
	Nivel();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	sf::FloatRect getBounds() const override;
	
	sf::Sprite getfondo() const;
};

