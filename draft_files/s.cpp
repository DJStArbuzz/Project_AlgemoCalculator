sf::RenderWindow window(sf::VideoMode(1000, 1000), "Арбуз ебет кавун");

sf::RectangleShape rectangle(sf::Vector2f(200, 75));
rectangle.setFillColor(sf::Color::Green);
rectangle.setOutlineThickness(5);
rectangle.setOutlineColor(sf::Color::Blue);
rectangle.setPosition(sf::Vector2f(25, 25));

sf::RectangleShape rectangle2(sf::Vector2f(200, 75));
rectangle2.setFillColor(sf::Color::Green);
rectangle2.setOutlineThickness(5);
rectangle2.setOutlineColor(sf::Color::Blue);
rectangle2.setPosition(sf::Vector2f(25, 125));

sf::RectangleShape rectangle3(sf::Vector2f(200, 75));
rectangle3.setFillColor(sf::Color::Green);
rectangle3.setOutlineThickness(5);
rectangle3.setOutlineColor(sf::Color::Blue);
rectangle3.setPosition(sf::Vector2f(25, 225));

sf::RectangleShape rectangle4(sf::Vector2f(200, 75));
rectangle4.setFillColor(sf::Color::Green);
rectangle4.setOutlineThickness(5);
rectangle4.setOutlineColor(sf::Color::Blue);
rectangle4.setPosition(sf::Vector2f(25, 325));

while (window.isOpen())
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    window.clear();
    window.draw(rectangle);
    window.draw(rectangle2);
    window.draw(rectangle3);
    window.draw(rectangle4);
    window.display();
}
