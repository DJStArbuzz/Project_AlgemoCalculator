#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

const int W = 1000;
const int H = 1000;

int o1 = -30;
int o2 = 30;
float c = 200;
int mass = ((o1) * (-1) + o2) * c + 1;
int sc = 20;
double k = 1;
double b = 0;

void bebr_2(int anim, int x0, int y0, CircleShape& point, RenderWindow& window) {

	Texture t;
	t.loadFromFile("C:/Plos.png");
	Sprite pic(t);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (anim < mass)
			anim += 100;
		if (Keyboard::isKeyPressed(Keyboard::Escape)) return;
		window.clear(Color::White);
		window.draw(pic);
		for (int i = 0; i < anim; i++) {
			float x = o1 + i / c;
			float y = k * -x + b;
			float y3 = 1 / x;

			float x1 = x0 + x * sc;
			float x2 = x0 + x * sc;
			float y1 = y0 - y * sc;
			float y2 = y0 - y3 * sc;

			point.setPosition(x1 - 1, y1 - 1);
			window.draw(point);
		}
		window.display();
	}
}

void bebr(int anim, int x0, int y0, CircleShape& point, RenderWindow& window) {

	Texture t;
	t.loadFromFile("C:/Plos.png");
	Sprite pic(t);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) return;
		if (anim < mass)
			anim += 100;

		window.clear(Color::White);
		window.draw(pic);
		for (int i = 0; i < anim; i++) {
			float x = o1 + i / c;
			float y = k * x + b;
			float y3 = 1 / x;

			float x1 = x0 + x * sc;
			float x2 = x0 + x * sc;
			float y1 = y0 - y * sc;
			float y2 = y0 - y3 * sc;

			point.setPosition(x1 - 1, y1 - 1);
			window.draw(point);
		}

		window.display();
	}
}



void arbuz_ebet_diny() {
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
}
void menu(RenderWindow& window, int anim, CircleShape& point) {

}

int main()
{
	RenderWindow window(VideoMode(W, H), "Function graph!");
	int anim = 0;
	CircleShape point(2.f);
	point.setFillColor(Color::Blue);
	int x0 = W / 2;
	int y0 = H / 2;
	Text text;
	text.setString("Zhopa");
	text.setCharacterSize(24);
	text.setPosition(x0 - 40, y0 - 17);
	Font font;
	font.loadFromFile("ariblk.ttf");
	text.setFont(font);

	Text text2;
	text2.setString("Zhopa");
	text2.setCharacterSize(24);
	text2.setPosition(x0 - 40, y0 + 60);
	text2.setFont(font);

	RectangleShape rectangle(Vector2f(120, 50));
	rectangle.setPosition(x0 - 60, y0 - 25);

	RectangleShape rectangle2(Vector2f(120, 50));
	rectangle2.setPosition(x0 - 60, y0 + 55);

	int menu_1 = 0;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		rectangle.setFillColor(Color::Green);
		rectangle2.setFillColor(Color::Green);
		window.clear(Color::White);
		text.setFillColor(Color::Blue);
		text2.setFillColor(Color::Blue);

		window.draw(rectangle);
		window.draw(rectangle2);
		if (IntRect(x0 - 60, y0 - 25, x0 + 60, y0 + 25).contains(Mouse::getPosition(window))) {
			text.setFillColor(Color::White); menu_1 = 1;
		}
		if (IntRect(x0 - 60, y0 + 55, x0 + 60, y0 + 105).contains(Mouse::getPosition(window))) {
			text2.setFillColor(Color::White); menu_1 = 2;
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menu_1 == 1) { bebr(anim, x0, y0, point, window); }
			if (menu_1 == 2) { arbuz_ebet_diny(); }
		}
		window.draw(text);
		window.draw(text2);
		window.display();
	}
	return 0;
}
