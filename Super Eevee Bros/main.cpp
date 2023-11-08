#include <iostream>
#include <SFML/Graphics.hpp>
#include "macros.h"
#include "Player.h"

int main()
{
    std::vector<sf::RectangleShape> platformes;
    sf::RectangleShape platforme(sf::Vector2f(500, 100));
    platforme.setOrigin(platforme.getSize().x / 2, 0);
    platforme.setPosition(900, 455);
    platformes.push_back(platforme);

    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "SFML works!");
    sf::Clock clock;

    window.setFramerateLimit(60);

    Player player;


    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();

        // inputs
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }

        player.ticks(deltaTime);
        player.inputs(platformes);

        // draw
        window.clear();
        window.draw(platforme);
        player.draw(window);
        window.display();
       
    }

    return 0;
}


//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
//int main(int argc, char** argv)
//{
//    // Create the main window
//    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
//    // Load a sprite to display
//
//    // Create a graphical text to display
//    //sf::Font font;
//    //if (!font.loadFromFile("arial.ttf"))
//    //    return EXIT_FAILURE;
//    //sf::Text text("Hello SFML", font, 50);
//    // Load a music to play
//    //sf::Music music;
//    //if (!music.openFromFile("nice_music.ogg"))
//    //    return EXIT_FAILURE;
//    // Play the music
//    //music.play();
//    // Start the game loop
//    while (window.isOpen())
//    {
//        // Process events
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            // Close window: exit
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//        // Clear screen
//        window.clear();
//        // Draw the sprite
//        // Draw the string
//        //window.draw(text);
//        // Update the window
//        window.display();
//    }
//    return EXIT_SUCCESS;
//}