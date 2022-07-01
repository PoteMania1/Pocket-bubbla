#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <ctime>
#include "GamePlay.h"

int main()
{
    std::srand((unsigned)std::time(0));

    //inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Poket Bubbla!");
    window.setFramerateLimit(60);

    GamePlay game;

    //Game Loop (update del juego)
    while (window.isOpen())
    {
        //ReadInput Actualiza los estados de los perifericos de entrada
        //Leer la cola de mensajes
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        // CMD - Joy
        game.cmd();
        

        // Update - Actualiza los estados del juego
        game.update();
        

        /*if (ash.isColision(Fruti)) {
              Fruti.respawn();
        }*/

        window.clear();
        //ash.draw(window);

        // Draw
     
        window.draw(game);
        //ash.draw(window);
        window.display();
        //window.draw(Fruti);
        // Display - Flip


    }

    //Liberacion del Juego

    return 0;
}