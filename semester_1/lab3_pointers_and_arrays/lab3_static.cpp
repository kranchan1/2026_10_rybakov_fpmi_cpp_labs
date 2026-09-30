
// solve task with usage of
// static arrays
#include <iostream>
#include <random>

const size_t MAX_LENGTH = 100'000;

void TryRead(int& num);
int NeedRandomFill();
void FillArr(int* arr, int size);
void DelElements(int* arr, int size, int M);
void PrintArray(int* arr, int size);

int main()
{
	setlocale(LC_ALL, "rus");
	int arr[MAX_LENGTH];
	int n, M;
	std::cout << "Введите размер массива: ";
	TryRead(n);
	std::cout << "Введите число M, такое что все элементы массива будут больше его по модулю: ";
	TryRead(M);
	FillArr(arr, n);
	DelElements(arr, n, M);
	PrintArray(arr, n);
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
		for (int i = 0; i < size; ++i) {
			arr[i] = dist(gen);
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';
	}
}

void DelElements(int* arr, int size, int M) {
	for (int i = 0; i < size; ++i) {
		if (abs(arr[i]) <= M) {
			arr[i] = 0;
		}
	}
	for (int i = 0; i < size - 1; ++i) {
		if (arr[i] == 0) {
			for (int j = 1; i + j < size; ++j) {
				if (arr[i + j] != 0) {
					arr[i] = arr[i + j];
					arr[i + j] = 0;
					break;
				}
			}
		}
	}
}

void PrintArray(int* arr, int size) {
	std::cout << "Редактированный массив: ";
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << ' ';
	}
}
