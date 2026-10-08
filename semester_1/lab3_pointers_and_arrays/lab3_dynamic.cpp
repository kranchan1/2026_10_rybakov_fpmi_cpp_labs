#include <iostream>
#include <random>

void TryRead(int& num);
int NeedRandomFill();
void FillArr(int* arr, int size);
int PalindromeArray(int* arr, int size);

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	std::cout << "Введите размер массива: ";
	TryRead(n);
	int* arr = new int[n];
	FillArr(arr, n);
	int max_palindrome = PalindromeArray(arr, n);
	std::cout << "Самый длинный палиндром в массиве имеет длину: " << max_palindrome;
	delete[] arr;
}

void TryRead(int& num) {
	if (!(std::cin >> num)) {
		std::cout << "\nНеккоректный ввод";
		std::exit(-1);
	}
}

int NeedRandomFill() {
	int random_arr;
	std::cout << "Введите 0, чтобы заполнить массив случайными числами или 1, чтобы заполнить его с клавиатуры: ";
	TryRead(random_arr);
	if (random_arr != 0 && random_arr != 1) {
		std::cout << "\nНеккоректный ввод. Введите 0 или 1";
		std::exit(-1);
	}
	return random_arr;
}
void FillArr(int* arr, int size) {
	int flag = NeedRandomFill();
	if (flag) {
		std::cout << "Введите элементы массива: ";
		for (int i = 0; i < size; ++i) {
			TryRead(arr[i]);
		}
	}
	else {
		int a, b;
		std::cout << "Введите границы интервала случайных чисел: \nНижняя граница: ";
		TryRead(a);
		std::cout << "Верхняя граница: ";
		TryRead(b);
		int min_a = (a < b) ? a : b;
		int max_b = (a < b) ? b : a;
		std::mt19937 gen(45218965);
		std::uniform_int_distribution<int> dist(min_a, max_b);
		std::cout << "Элементы массива: ";
		for (int i = 0; i < size; ++i) {
			arr[i] = dist(gen);
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';
	}
}

int PalindromeArray(int* arr, int size) {
	int palindrome_length = (size == 0) ? 0 : 1;
	for (int i = 1; i < size - 1; ++i) {
		int j = 1;
		while ((arr[i - j] == arr[i + j]) && (i - j > -1) && (i + j < size)) {
			j += 1;
		}
		if (palindrome_length < 2 * (j - 1) + 1) {
			palindrome_length = 2 * (j - 1) + 1;
		}
		j = 1;
		while ((arr[i - j + 1] == arr[i + j]) && (i - j + 1 > -1) && (i + j < size)) {
			j += 1;
		}
		if (palindrome_length < 2 * (j - 1)) {
			palindrome_length = 2 * (j - 1);
		}
	}
	return palindrome_length;
}

