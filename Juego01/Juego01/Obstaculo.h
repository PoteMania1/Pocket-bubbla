#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"


	class Obstaculo : public sf::Drawable, public colisionable, public sf::Transformable
	{
	private:
		
		sf::Texture _texture1;
		sf::Sprite _obst1;
		sf::Sprite _obst2;
		sf::Sprite _obst3;
		sf::Sprite _obst4;
		int _frame = 0;
	public:
		Obstaculo();
		void update();
		void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
		sf::Sprite getobst1() const;
		sf::Sprite getobst2() const;
		sf::Sprite getobst3() const;
		sf::Sprite getobst4() const;
		void setobst1();
		void setobst2();
		void setobst3();
		void setobst4();
		sf::FloatRect getBounds() const override;
		sf::Vector2f getposition1() const;
	};


