#include <iostream>
#include <cmath>
int main() {
	setlocale(LC_ALL, "rus");
	using std::cin;
	using std::cout;
	unsigned long long n, n_copy, n_reverse;
	cout << "Введите целое неотрицательное число до 18 знаков: ";
	if (!(cin >> n)) {
		cout << "Ошибка. Введите целое неотрицательное число до 18 знаков\n";
		std::exit(-1);
	}
	n_copy = n;
	n_reverse = n;
	// циклом while поочередно перебираем числа от 0 до 9 подсчитываем каждое если четное кол-во то перебираем цифры числа заново и данное число не вставляем в n
	for (int i = 0; i <= 9; ++i) {
		int counter = 0;
		while (n_copy > 0) {
			int num;
			num = n_copy % 10;
			n_copy /= 10;
			if (num == i) { ++counter; }
		}
		n_copy = n_reverse;
		if (counter % 2 == 0) {
			int deg = 0;
			n_reverse = 0;
			while (n_copy > 0) {
				int num;
				num = n_copy % 10;
				n_copy /= 10;
				if (num != i) {
					n_reverse = n_reverse + num * pow(10, deg);
					++deg;
				}
			}
		}
		n_copy = n_reverse;
	}
	cout << "Число без цифр встречающихся четное количество раз: " << n_reverse;
	return 0;
}