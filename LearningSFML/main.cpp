#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

struct Positions {
    int rodaX;
    int rodaY;
};

int main() {

    Positions teste;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
        float raio = 30;
        sf::CircleShape roda(raio);
        roda.setFillColor(sf::Color::Blue);

        while (window.isOpen()) {
            sf::Event event;

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::MouseMoved) {
                    if (event.mouseMove.x) {
                        teste.rodaX = event.mouseMove.x;
                    }
                    if (event.mouseMove.y) {
                        teste.rodaY = event.mouseMove.y;
                    }
                }

            }
        window.clear();

        roda.setPosition(sf::Vector2f(teste.rodaX, teste.rodaY));

        window.draw(roda);
        window.display();
    }
    return 0;
}
