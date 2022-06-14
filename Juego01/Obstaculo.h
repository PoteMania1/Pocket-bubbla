#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"


	class Obstaculo : public sf::Drawable, public colisionable, public sf::Transformable
	{
	private:
		
		sf::Texture _texture1;
		sf::Sprite _obst1[10];
		int _frame = 0;
	public:
		Obstaculo();
		void update();
		void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
		sf::Sprite getobst1() const;
		void setobst1();
		sf::FloatRect getBounds() const override;
		sf::Vector2f getposition1() const;
	};


