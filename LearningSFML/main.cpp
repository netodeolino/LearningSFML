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

    sf::Texture tex_dilma;
    tex_dilma.loadFromFile("../LearningSFML/dilma.png");
    sf::Sprite sprite_dilma(tex_dilma);

    sf::Texture tex_coroa;
    tex_coroa.loadFromFile("../LearningSFML/coroa.png");
    sf::Sprite sprite_coroa(tex_coroa);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Coloque a coroa na Rainha");
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

        //roda.setPosition(sf::Vector2f(teste.rodaX, teste.rodaY));
        sprite_dilma.setPosition(300, 200);
        sprite_coroa.setPosition(sf::Vector2f(teste.rodaX, teste.rodaY));

        window.draw(sprite_coroa);
        window.draw(sprite_dilma);
        //window.draw(roda);

        window.display();
    }
    return 0;
}
