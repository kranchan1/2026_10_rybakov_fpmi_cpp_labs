#include <iostream>

int main()
{
	//int + нач позиция календаря за счет сдвигов по номеру дня минкс 1(сам день)
	int n, k, i;
	setlocale(LC_ALL, "rus");
	std::cout << "Введите n: ";
	std::cin >> n;
	std::cout << "Введите k: ";
	std::cin >> k;
	for (i = 1; i < n; ++i) {
		std::cout << "   ";
	}
	//for используем i в качестве номера дня + определяем смену недели используя формулу n+i-1 и переводим строку
	for (i = 1; i <= k; ++i) {
		if (i <= 9) {
			std::cout << ' ' << i << ' ';
		}
		else {
			std::cout << i << ' ';
		}
		if ((i + n - 1) % 7 == 0) {
			std::cout << '\n';
		}
	}
}
