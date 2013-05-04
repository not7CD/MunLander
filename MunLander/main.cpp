#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
#include <iostream>

#include "cLander.h"

int main()
{
	/// inicjalizacja okna gry
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mun Lander! Prototyp");
	window.setFramerateLimit(80);
	/// ekran �adowania

	std::cout << "MunLander! wersja 0.0000042\nKwadrat ma przyspiezeszenie ma max 5 m/s^2 i NaN paliwa\nNa kwadrat oddziauje przyspieszenie 1,63 m/s^2 (jak na Munie)\n";

	/// inicjalizacja zmiennych i obiekt�w gry
	sf::Event event;

	sf::Clock zegFiz;
	sf::Time czasFiz;
	sf::Clock zegPkt;
	sf::Time czasPkt;

	

	/// test
	cLander test;
 
	float gravA = 1.63f;
		
	

	/// g��wna p�tla gry

    while (window.isOpen())
    {
		/// obs�uga klawiatury i myszy

        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
			{
                window.close();
				
			}

			if (event.type ==  sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
			{
				test.rotateObject(2);
			}

			if (event.type ==  sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
			{
				test.rotateObject(-2);
			}

			if (event.type ==  sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
			{
				test.accelerateObject(1);
			}

			if (event.type ==  sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
			{
				test.accelerateObject(-1);
			}
        }
		
		/// liczenie fizyki itp.
		czasFiz = zegFiz.getElapsedTime();
		zegFiz.restart();

		/// ustawianie obiekt�w
		test.loopObject( window, czasFiz, gravA);
		/// czyszczenie ekranu
        window.clear();
		/// rysowanie obiekt�w

		test.drawObject( window );
		
		/// wy�wietlanie
        window.display();
    }

    return 0;
}