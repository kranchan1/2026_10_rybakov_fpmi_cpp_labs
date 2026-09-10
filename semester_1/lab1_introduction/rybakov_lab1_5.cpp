#include <iostream>

int main()
{
	// int i, три члена(а0, а1, а2)
	//for от 1 до n считаем + выводим
	int n, a0 = 0, a1 = 1, a2;
	setlocale(LC_ALL, "rus");
	std::cout << "Введите сколько первых членов последовательности Фибоначчи необходимо вывести: ";
	std::cin >> n;
	std::cout << "Числа Фибоначчи: " << a1 << ' ';
	for (int i = 1; i != n; ++i) {
		a2 = a0 + a1;
		a0 = a1;
		a1 = a2;
		std::cout << a2 << ' ';
	}
	return 0;
}
