#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"


	class Obstaculo : public sf::Drawable, public colisionable, public sf::Transformable
	{
	private:
		
		sf::Texture _texture1;
		sf::Texture _texture2;
		sf::Texture _texture3;
		sf::Sprite _obst1;
		sf::Sprite _obst2;
		sf::Sprite _obst3;
		int _frame = 0;
	public:
		Obstaculo();
		void update();
		void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
		sf::Sprite getobst1() const;
		void setobst1();
		sf::FloatRect getBounds() const override;
		sf::Vector2f getposition1() const;
		sf::Sprite getSprite1()const;
		void CargarVecObst(sf::Sprite*,int);
	};


