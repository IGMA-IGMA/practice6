#include <SFML/Graphics.hpp>

int main()
{
    int matrixSize = 12;
    const int cellSize = 40;

    sf::RenderWindow window(sf::VideoMode(matrixSize * cellSize, matrixSize * cellSize), "Centered Square");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        int squareSize = matrixSize - 6;
        int offset = (matrixSize - squareSize) / 2;

        for (int i = 0; i < matrixSize; ++i)
        {
            for (int j = 0; j < matrixSize; ++j)
            {
                sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
                cell.setPosition(i * cellSize, j * cellSize);

                if (i >= offset && i < offset + squareSize &&
                    j >= offset && j < offset + squareSize) {
                    cell.setFillColor(sf::Color::Green);
                }
                else {
                    cell.setFillColor(sf::Color::White);
                }

                cell.setOutlineColor(sf::Color::Black);
                cell.setOutlineThickness(1);
                window.draw(cell);
            }
        }

        window.display();
    }

    return 0;
}
