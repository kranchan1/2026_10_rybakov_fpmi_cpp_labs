
#include <iostream>
int main() {
	int num, a, b, c, d, e, f, Sum_abc, Sum_def;
	setlocale(LC_ALL, "rus");
	std::cout << "Введите шестизначное число, чтобы узнать является ли оно волшебным:";
	std::cin >> num;
	a = num / 100000;
	b = (num % 100000) / 10000;
	c = (num % 10000) / 1000;
	d = (num % 1000) / 100;
	e = (num % 100) / 10;
	f = num % 10;
	Sum_abc = a + b + c;
	Sum_def = d + e + f;
	if (Sum_abc == Sum_def) {
		std::cout << "Число является счастливым";
	}
	else {
		std::cout << "Число не является счастливым";
	}
}