#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <string>

const float PI = acos(-1);

using namespace sf;
using namespace std;

const int W = 1000;
const int H = 1000;

int o1 = -30;
int o2 = 30;
float c = 200;
int mass = ((o1) * (-1) + o2) * c + 1;
int sc = 20;
double k = 1;
double b = 0;

// Процедура вывода теории
// Пункт 0
void theory() {
	cout << "Прямая на плоскости" << endl;

	cout << "Общее уравнение прямой: Ax + By + C = 0." << endl;

	cout << "С угловым коэффициентом уравнение прямой: y = kx + b, где k = tg(a), α –" <<
		"угол наклона к оси Ox." << endl;

	cout << "Нормальное уравнение прямой: x*cos(a) + y*sin(a) − ρ = 0, где a – полярный" <<
		"угол нормали, ρ – длина вектора нормали до прямой." << endl;

	cout << "Отклонение точки от прямой δ = x0 cos α + y0 sin α − ρ. Расстояние от точки до" <<
		"прямой равно модулю отклонения." << endl;

	cout << "Через точки M1 и M2 уравнение прямой, где M1 = (x1, y1), M2 = (x1, y1): " << endl;
	cout << " x - x1      y - 1 " << endl;
	cout << "-------  =  -------" << endl;
	cout << "x2 - x1     y2 - y1" << endl;

	cout << "Если известны угловые коэффициенты двух прямых k1 и k2, то один из углов a между прямыми : " << endl;
	cout << "         k2 - k1 " << endl;
	cout << "tg(a) = ---------" << endl;
	cout << "        1 + k1*k2 " << endl;

	cout << "В отрезках уравнение прямой, где a и b – величины отрезков, которые отсекает прямая на координатных осях:" << endl;
	cout << "x   y " << endl;
	cout << "- + - = 1" << endl;
	cout << "a   b" << endl;

	cout << endl;

}

// Процедура поиска угла наклона
// Пункт 1
double search_for_the_angular_coefficient(bool flag) {
	cout << "Введите уравнение вида: ";
	cout << "y = kx + b" << endl;

	double tmp, k, b;
	/*
		tmp - переменная, стоящая перед y.
		k - неотредактированный коэффициент.
		b - отсекаемый отрезок на оси Oy.
	*/

	double tan_tmp, atan_tmp;
	/*
		tan_tmp - угловой коэффициент

		y = kx + b, где k = tg(a),
		a - угол наклона к оси Ox.

	*/

	cout << "Введите параметры y и x и отрезок, отсекаемый на оси Оу.\n" << endl;

	cout << "Для y: ";
	cin >> tmp;

	cout << "Для x: ";
	cin >> k;

	cout << "b: ";
	cin >> b;

	cout << "\nТангенс угла наклона к оси Ox: ";
	tan_tmp = k / tmp;

	cout << fixed << setprecision(3) << k << " / " << tmp << endl;

	cout << "\nТангенс угла наклона к оси Ox: ";
	cout << fixed << setprecision(3) << tan_tmp << endl;

	if (flag) {
		cout << "Угол наклона к оси Ox: ";
		atan_tmp = atan(tan_tmp) * 180 / PI;
		cout << fixed << setprecision(3) << atan_tmp << endl;
	}
	else {
		return tan_tmp;
	}

	cout << endl;
}

// Процедура составления уравнения прямой через одну некоторую точку
// Пункт 2
void drawing_up_the_equation_one_point() {
	/*
		y - y0 = k * (x - x0)
		y = kx - kx0 + y0

		k = tg(a), a - угол наклона к оси Ox,
		M = (x0, y0) - точка, лежащая на прямой
		(-kx0 + y0) = b - отсекаемый отрезок на оси Oy.
	*/

	pair <double, double> coordinates;
	/*
		Переменная, собирающая координаты точки.
		first - абсцисса,
		second - ордината.
	*/
	cout << "Введите координаты некоторой точки: ";
	cin >> coordinates.first >> coordinates.second;

	cout << "Уравнение прямой: y = k * x - k * " << coordinates.first;
	cout << " + " << coordinates.second << endl;

	cout << endl;
}

// Процедура составления уравнения прямой через две некоторые точки
// Пункт 3
void drawing_up_the_equation_two_point() {
	/*
		x - x1    y - y1
		------- = -------
		x2 - x1   y2 - y1

		(x - x1)*(y2 - y1) = (x2 - x1)*(y - y1)
		x * (y2 - y1) - x1 * (y2 - y1) = y * (x2 - x1) - y1 * (x2 - x1)

		delta() = d()
		Пусть d(y) = y2 - y1, d(x) = x2 - x1

		x * d(y) - x1 * d(y) = y * d(x) - y1 * d(x)
		x * d(y) - x1 * d(y) + y1 * d(x) = y * d(x) | :(d(x)

		y = (d(y) / d(x)) * x + (-x1 * d(y) + y1 * d(x)) / d(x)
	*/

	pair <double, double> coordinates_first;
	pair <double, double> coordinates_second;
	/*
		Переменные, собирающие координаты точки.
		first - абсцисса,
		second - ордината.
	*/

	cout << "Введите координаты первой некоторой точки: ";
	cin >> coordinates_first.first >> coordinates_first.second;

	cout << "Введите координаты второй некоторой точки: ";
	cin >> coordinates_second.first >> coordinates_second.second;

	double delta_x = coordinates_second.first - coordinates_first.first;
	double delta_y = coordinates_second.second - coordinates_first.second;

	double div_delta = delta_y / delta_x;
	double tmp = (coordinates_first.second * delta_x - coordinates_first.first * delta_y) / delta_x;

	cout << fixed << setprecision(3) << "Уравнение прямой: y = x * " << div_delta
		<< " + (" << tmp << ")" << endl;

	cout << "Уравнение прямой: y = x * (" << delta_y << " / " << delta_x
		<< ") + (" << coordinates_first.second * delta_x << " - " <<
		coordinates_first.first * delta_y << ") / " << delta_x << endl;

	cout << endl;
}

// Процедура нахождения угла между прямыми
// Пункт 4
void find_angle_between_straight_lines() {
	/*			 k2 - k1
		tg(a) = --------- , где k1 и k2 - угловые коэффициенты
				1 + k1*k2
		a - один из углов между прямыми

	*/

	double tan_tmp, atan_tmp;
	double k1 = search_for_the_angular_coefficient(false);
	cout << endl;

	double k2 = search_for_the_angular_coefficient(false);

	cout << "\nУгол между прямыми: ";
	tan_tmp = abs((k2 - k1) / (1 + k1 * k2));
	atan_tmp = atan(tan_tmp) * 180 / PI;
	cout << fixed << setprecision(3) << atan_tmp << endl;

	cout << endl;
}

// Процедура изменения уравнения прямой из общего вида в нормальное.
// Пункт 5
void classic_to_normal() {
	cout << "Введите уравнение вида: ";
	cout << "y = kx + b" << endl;

	double tmp, k, b;
	cout << "Введите параметры y и x и отрезок, отсекаемый на оси Оу.\n" << endl;

	cout << "Для y: ";
	cin >> tmp;

	tmp *= -1;

	cout << "Для x: ";
	cin >> k;

	cout << "b: ";
	cin >> b;

	cout << "Вы ввели: " << tmp << "y + (" << k << ")x + (" << b << ") = 0\n" << endl;

	double del = sqrt(pow(tmp, 2) + pow(k, 2));

	bool check = (((pow(tmp, 2) + pow(k, 2)) / pow(del, 2)) == 1);

	if (check) {
		cout << "Уравнение нормального вида: \n(";

		cout << tmp << " / " << del << ")y + (" << k << " / " << del << ")x + (" << b << "/" << del << ") = 0" << endl;

		if (b / del > 0) {
			tmp *= -1;
			k *= -1;
			cout << "(" << tmp << " / " << del << ")y + (" << k << " / " << del << ")x - (" << b << "/" << del << ") = 0" << endl;
		}
	}
	else {
		cout << "Уравнение невозможно изменить." << endl;
	}
	cout << endl;
}

// Процедура изменения уравнения прямой из нормального вида в общее.
// Пункт 6
void normal_to_classic() {
	cout << "Введите уравнение вида: ";
	cout << "x * cos(a) + y * sin(a) - p = 0" << endl;
	cout << "a - полярный угол нормали, ρ – длина вектора нормали до прямой." << endl;

	pair<double, double> cosA;
	cout << "cos(a): ";
	cin >> cosA.first;
	cout << "/";
	cin >> cosA.second;

	pair<double, double> sinA;
	cout << "sin(a): ";
	cin >> sinA.first;
	cout << "/";
	cin >> sinA.second;
	cout << endl;

	double p;
	cout << "p: ";
	cin >> p;

	if (sinA.second < 0) {
		sinA.second *= -1;
		sinA.first *= -1;
	}

	if (cosA.second < 0) {
		cosA.second *= -1;
		cosA.first *= -1;
	}

	if (sinA.second == 0 || cosA.second == 0) {
		cout << "Невозможно решить." << endl;
	}
	else {
		cout << "Вы ввели: ";
		cout << "x * (" << cosA.first << "/" << cosA.second << ") + y * (" << sinA.first << "/" << sinA.second
			<< ") - " << p << " = 0" << endl;

		cout << "Общий вид уравнения прямой: ";
		if (sinA.second == cosA.second) {
			cout << "x * (" << cosA.first << ") + y * (" << sinA.first
				<< ") - " << p * sinA.second << " = 0" << endl;
		}
		else {
			double denominator_sin = sinA.second;
			double denominator_cos = cosA.second;

			sinA.first *= denominator_cos;
			sinA.second *= denominator_cos;

			cosA.first *= denominator_sin;
			cosA.second *= denominator_sin;

			bool check = ((pow(cosA.first, 2) + pow(sinA.first, 2)) / pow(sinA.second, 2) == 1);
			if (check) {
				cout << "x * (" << cosA.first << ") + y * (" << sinA.first
					<< ") - " << p * sinA.second << " = 0" << endl;
			}
			else {
				cout << " невозможен." << endl;
			}
		}
	}
	cout << endl;
	cout << endl;
}

// Процедура поиска отклонения
// Пункт 7.
void find_deviation() {
	cout << "Введите уравнение вида: ";
	cout << "x * cos(a) + y * sin(a) - p = 0" << endl;
	cout << "a - полярный угол нормали, ρ – длина вектора нормали до прямой." << endl;

	pair<double, double> cosA;
	cout << "cos(a): ";
	cin >> cosA.first;
	cout << "/";
	cin >> cosA.second;

	pair<double, double> sinA;
	cout << "sin(a): ";
	cin >> sinA.first;
	cout << "/";
	cin >> sinA.second;
	cout << endl;

	double p;
	cout << "p: ";
	cin >> p;

	pair <double, double> coordinates;
	cout << "Введите координаты некоторой точки: ";
	cin >> coordinates.first >> coordinates.second;

	cout << "\nОтклонение графика: ";

	double result = coordinates.first * cosA.first / cosA.second +
		coordinates.second * sinA.first / sinA.second - p;

	cout << result << endl;
	cout << endl;
}

// Процедура выхода из программы
// Пункт -1.
void exiting_the_program() {
	cout << "Сеанс завершен." << endl;
	exit(0);
}

// Процедура вывода возможных операций
void menu() {
	cout << "0. Теория." << endl;
	cout << "1. Найти угол наклона." << endl;
	cout << "2. Составить уравнение прямой по одной точке." << endl;
	cout << "3. Составить уравнение прямой по двум точкам." << endl;
	cout << "4. Найти угол между прямыми." << endl;
	cout << "5. Переделать уравнение прямой из общего вида в нормальное." << endl;
	cout << "6. Переделать уравнение прямой из нормального вида в общее." << endl;
	cout << "7. Найти отклонение от прямой." << endl;
	cout << "Ваш выбор: ";
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
			float y = k * 0.5 * x + b;

			float x1 = x0 + x * sc ;
			float y1 = y0 - y * sc;

			point.setPosition(x1 - 1, y1 - 1);
			window.draw(point);
		}

		window.display();
	}
}

void oper_with_masunya(RectangleShape &rectangle, int x, int y) {
	rectangle.setFillColor(sf::Color::Green);
	rectangle.setOutlineThickness(5);
	rectangle.setOutlineColor(sf::Color::Blue);
	rectangle.setPosition(sf::Vector2f(x, y));
}

void arbuz_ebet_diny(RenderWindow &window) {
	window.clear(Color::White);

	int sizeX = 200, sizeY = 75;
	int x1 = 25, x2 = 250;
	int y = 25;

	Text text;
	text.setString("Zhopa");
	text.setCharacterSize(24);
	text.setPosition(x1, 875);
	text.setFillColor(Color::Blue);

	RectangleShape rectangle1(Vector2f(sizeX, sizeY));
	RectangleShape rectangle2(Vector2f(sizeX, sizeY));
	RectangleShape rectangle3(Vector2f(sizeX, sizeY));
	RectangleShape rectangle4(Vector2f(sizeX, sizeY));
	RectangleShape rectangle5(Vector2f(sizeX, sizeY));
	RectangleShape rectangle6(Vector2f(sizeX, sizeY));
	RectangleShape rectangle7(Vector2f(sizeX, sizeY));
	RectangleShape rectangle8(Vector2f(sizeX, sizeY));
	
	RectangleShape rectangleMenu(Vector2f(425, 400));
	RectangleShape rectangleReturn(Vector2f(100, 100));


	oper_with_masunya(rectangle1, x1, y + 100 * 0);
	oper_with_masunya(rectangle2, x1, y + 100 * 1);
	oper_with_masunya(rectangle3, x1, y + 100 * 2);
	oper_with_masunya(rectangle4, x1, y + 100 * 3);
	oper_with_masunya(rectangle5, x2, y + 100 * 0);
	oper_with_masunya(rectangle6, x2, y + 100 * 1);
	oper_with_masunya(rectangle7, x2, y + 100 * 2);
	oper_with_masunya(rectangle8, x2, y + 100 * 3);

	oper_with_masunya(rectangleMenu, x1, y + 110 * 4 - 10);
	oper_with_masunya(rectangleReturn, x1, 875);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(rectangle1);
		window.draw(rectangle2);
		window.draw(rectangle3);
		window.draw(rectangle4);

		window.draw(rectangle5);
		window.draw(rectangle6);
		window.draw(rectangle7);
		window.draw(rectangle8);

		window.draw(rectangleMenu);
		
		window.draw(rectangleReturn);
		window.draw(text);

		window.display();

		if (IntRect(25, 875, 125, 975).contains(Mouse::getPosition(window))) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				exit(0);
			}
		}
	}
}

void menu_graph() {
	int anim = 0;
	int x0 = W / 2;
	int y0 = H / 2;
	int menu_1 = 0;

	RenderWindow window(VideoMode(W, H), "Verynchic");
	CircleShape point(2.f);
	point.setFillColor(Color::Blue);

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
			if (menu_1 == 1)
			{
				bebr(anim, x0, y0, point, window);
			}
			if (menu_1 == 2)
			{
				arbuz_ebet_diny(window);
			}
		}

		window.draw(text);
		window.draw(text2);
		window.display();
	}
}

int main()
{
	while (true) {
		menu_graph();
	}
	return 0;
}
