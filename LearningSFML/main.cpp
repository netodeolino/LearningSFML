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

    sf::Font font;
    if (!font.loadFromFile("../LearningSFML/open-sans.ttf")){
        return EXIT_FAILURE;
    }
    sf::Text text("Parabéns, Você ganhou!", font, 50);
    text.setColor(sf::Color::Green);
    text.setPosition(300, 100);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Coloque a coroa na Rainha");

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

        //Collision
        if ((sprite_coroa.getPosition().x <= 300) && (sprite_coroa.getPosition().x > 250)) {
            if ((sprite_coroa.getPosition().y <= 140) && (sprite_coroa.getPosition().y > 130)) {
                //cout << "PASSOU" << endl;
                // Não está funfando
                window.draw(text);
            }
        }

        window.clear();

        sprite_dilma.setPosition(300, 200);
        sprite_coroa.setPosition(sf::Vector2f(teste.rodaX, teste.rodaY));


        window.draw(sprite_coroa);
        window.draw(sprite_dilma);
        //window.draw(text);

        window.display();
    }
    return 0;
}
