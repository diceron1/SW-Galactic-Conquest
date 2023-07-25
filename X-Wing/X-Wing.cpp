//Copyright Ron Dice 2023
//X-Wing 
#include <iostream>
#include <string>
#include <vector>

#include "Pilot.h"
#include "StarrySkyGenerator.h"

//sfml includes
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


using namespace std;
//New namespace, can use to replace sf (sf::window)
using namespace sf;

int main()
{
    //Window
    sf::RenderWindow screen(sf::VideoMode(1080, 720), "X-Wing Pilot", sf::Style::Fullscreen | sf::Style::Close);
    sf::Event event;
    
    


    //Load 32-bit X-Wing image, set it to xWingTexture
    sf::Texture xWingTexture;
    if(!xWingTexture.loadFromFile("/Users/Bubs/Desktop/C++Projects/X-Wing/Art/xwing.png")) //Handle the error if the image fails to load.
    {
        return 1;
    }


    //Creaate SkyGenerator
    StarrySkyGenerator starrySky(screen.getSize().x, screen.getSize().y);

    //Create Pilot
    Pilot pilot(xWingTexture, screen);



    //Game loop
    Clock clock;
    sf::Time dt;
    while (screen.isOpen())
    {
        dt = clock.restart();

        //Event polling
        while (screen.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed: 
                screen.close();
                break;

            case sf::Event::KeyPressed: 
                if(event.key.code == sf::Keyboard::Escape)
                    screen.close();
                break; 

            default:
                break;
            }
        }

       
        //update
        pilot.update(dt);
        pilot.updateProjectiles(dt);


        starrySky.update(pilot.getVelocity(), dt.asSeconds());

        //render
        screen.clear(); //Clear previous frame

        //Draw the starry sky
        starrySky.draw(screen);


        //Draw your game
        pilot.draw(screen);
        pilot.drawProjectiles(screen);
        screen.display();//Tell app window is done drawing
    }

    return 0;//End of application
}