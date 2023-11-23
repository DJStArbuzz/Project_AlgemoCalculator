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

using namespace std;

void theory() {

}

// Процедура поиска угла наклона
// Пункт 1
void search_for_the_angular_coefficient() {
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
	cout << fixed << setprecision(3) << tan_tmp << endl;

	cout << "Угол наклона к оси Ox: ";
	atan_tmp = atan(tan_tmp) * 180 / PI;
	cout << fixed << setprecision(3) << atan_tmp << endl;

	cout << endl;
}

// Составление уравнения прямой через одну некоторую точку
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

	cout << "Уравнение прямой: y = x * " << div_delta;
	cout << " + (" << tmp << ")" << endl;
	cout << endl;
}

// Процедура выхода из программы
// Пункт 8.
void exiting_the_program() {
	cout << "Сеанс завершен." << endl;
	exit(0);
}

// Процедура вывода возможных операций
void menu() {
	cout << "1. Найти угол наклона." << endl;
	cout << "2. Составить уравнение прямой по одной точке." << endl;
	cout << "3. Составить уравнение прямой по двум точкам." << endl;
	cout << "4. Найти угол между прямыми." << endl;
	cout << "5. Переделать уравнение прямой в общем виде в нормальное." << endl;
	cout << "6. Переделать уравнение прямой в нормальном виде в общем." << endl;
	cout << "7. Найти отклонение от прямой." << endl;
	cout << "8. Выход из программы." << endl << endl;
	cout << "Ваш выбор: ";
}

// Процедура выбора операции
void choose_number_of_problem() {
	menu();

	int number_of_problem;  // Выбор вопроса
	cin >> number_of_problem;

	cout << endl;

	switch (number_of_problem)
	{
	case(0):
		theory();
		break;
	case(1):
		search_for_the_angular_coefficient();
		break;
	case(2):
		drawing_up_the_equation_one_point();
		break;
	case(3):
		drawing_up_the_equation_two_point();
		break;
	case(4):
		break;
	case(5):
		break;
	case(6):
		break;
	case(7):
		break;
	case(8):
		exiting_the_program();
		break;

	default:
		break;
	}
}


int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Курс ЯрГУ ПМИ 1-ый курс, 1-ый семестр" << endl;
	cout << "Прямая на плоскости\n" << endl;

	while (true) {
		choose_number_of_problem();
	}
}
