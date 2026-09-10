#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");
	int a, b, d;
	std::cout << "Введите значение а: ";
	std::cin >> a;
	std::cout << "Введите значение b: ";
	std::cin >> b;
	std::cout << "Введите значение разности арифметической прогрессии d: ";
	std::cin >> d;
	for (int i = 1; a <= b; ++i) {
		if ((a % 3) == 0) {
			std::cout << a << ' ';
		}
		a += d;
	}
}