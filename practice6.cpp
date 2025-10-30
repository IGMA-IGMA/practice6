#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 500,500 }), "Picture");

    window.clear();

    int n = 10;

    const int cellSize = 50;
    const int gridSize = 10;

    sf::RectangleShape cells[gridSize][gridSize];


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        for (int i = 0; i < gridSize; ++i)
        {
            for (int j = 0; j < gridSize; ++j)
            {
                cells[i][j].setSize(sf::Vector2f(cellSize - 1, cellSize - 1));
                cells[i][j].setPosition(i * cellSize, j * cellSize);

                if ((i != 0 and i != 1 and i != 2 and i != n - 1 and i != n - 2 and i != n - 3) and (j != 0 and j != 1 and j != 2 and j != n - 1 and j != n - 2 and j != n - 3)) {
                    cells[i][j].setFillColor(sf::Color::Green);
                }
                else {
                    cells[i][j].setFillColor(sf::Color::White);
                }

                cells[i][j].setOutlineColor(sf::Color::Black);
                cells[i][j].setOutlineThickness(1);
                window.draw(cells[i][j]);
            }
        }
        window.display();
    }

    return 0;
    sf::sleep(sf::seconds(50));
}