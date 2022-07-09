#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <ctime>
#include "GamePlay.h"
#include "MainMenu.h"


int main()
{
    std::srand((unsigned)std::time(0));

    //inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pocket Bubbla!");
    window.setFramerateLimit(60);
    MainMenu mainmenu(800, 600);
    bool play = false;
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
            switch (event.type)
            {
            case sf::Event::KeyReleased:

                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    mainmenu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    mainmenu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (mainmenu.MainMenuPressed())
                    {
                    case 0:
                        std::cout << "Play button has been pressed" << std::endl;
                        play = true;
                        break;
                    case 1:
                        std::cout << "Option button has been pressed" << std::endl;
                        break;
                    case 2:
                        std::cout << "about button has been pressed" << std::endl;
                        break;
                    case 3:
                        window.close();
                        break;
                    }

                    break;
                }

                break;
            case sf::Event::Closed:
                window.close();

                break;

            }
        }

        // CMD - Joy
        if (play) {
            game.cmd();
        }
        // Update - Actualiza los estados del juego
        if (play) {
            game.update();
        }


        window.clear();

        // Draw
        mainmenu.draw(window);
        if(play){
            window.draw(game);
        }

        // Display - Flip
        window.display();


    }

    //Liberacion del Juego

    return 0;
}