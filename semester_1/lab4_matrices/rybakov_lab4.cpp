#include <iostream>
#include <random>

void TryRead(int& num) {
	if (!(std::cin >> num)) {
		std::cout << "Некорректный ввод\n";
		std::exit(-1);
	}
}

void FillRandom(int** matrix, int rows, int cols, std::mt19937* gen, int a, int b) {
	int min_a = (a < b) ? a : b;
	int max_b = (a < b) ? b : a;
	std::uniform_int_distribution<int> dist(min_a, max_b);
	std::cout << "Элементы массива:\n";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			matrix[i][j] = dist(*gen);
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << '\n';
	}
}
int NeedRandomFill() {
	int flag;
	std::cout << "Введите 0, чтобы заполнять матрицу автоматически, введите 1, чтобы заполнить матрицу вручную: ";
	TryRead(flag);
	if ((flag != 0) && (flag != 1)) {
		std::cout << "Некорректный ввод\n";
		std::exit(-1);
	}
	return flag;
}

void FillMatrix(int **matrix, int rows, int cols, std::mt19937* gen) {
	int flag = NeedRandomFill();
	if (flag) {
		std::cout << "Введите элементы матрицы: ";
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				int element;
				TryRead(element);
				matrix[i][j] = element;
			}
		}
	}
	else {
		int a, b;
		std::cout << "Введите нижнюю границу случайных чисел: ";
		TryRead(a);
		std::cout << "Введите верхнюю границу случайных чисел: ";
		TryRead(b);
		FillRandom(matrix, rows, cols, gen, a, b); 
	}
}

int** MatrixMultiply(int** matrix, int rows, int cols) {
	int** final_matrix = new int* [rows];
	for (int i = 0;i < rows;++i) {
		final_matrix[i] = new int[rows];
	}
	for (int i = 0;i < rows;++i) {
		for (int j = 0;j < rows;++j) {
			int sum = 0;
			for (int k = 0;k < cols;++k) {
				sum += matrix[i][k] * matrix[j][k];
			}
			final_matrix[i][j] = sum;
		}
	}
	return final_matrix;
}

int** SqMatrixMultiply(int** matrix, int rows, int cols) {
	int** final_matrix = new int* [rows];
	for (int i = 0;i < rows;++i) {
		final_matrix[i] = new int[rows];
	}
	for (int i = 0;i < rows;++i) {
		for (int j = 0;j < rows;++j) {
			int sum = 0;
			for (int k = 0;k < cols;++k) {
				sum += matrix[i][k] * matrix[k][j];
			}
			final_matrix[i][j] = sum;
		}
	}
	return final_matrix;
}

void PrintMatrix(int** matrix, int rows, int cols) {
	std::cout << "Результат умножения матриц:\n";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << '\n';
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	int rows, cols;
	std::cout << "Введите число строк матрицы: ";
	TryRead(rows);
	std::cout << "Введите число столбцов матрицы: ";
	TryRead(cols);
	if ((rows < 0) || (cols < 0)) {
		std::cout << "Некорректный ввод, размеры матрицы должен быть больше 0\n";
		std::exit(-1);
	}
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		matrix[i] = new int[cols];
	}
	std::mt19937 gen(45218965);
	FillMatrix(matrix, rows, cols, &gen);
	int** answer_matrix;
	if (rows != cols) {
		answer_matrix = MatrixMultiply(matrix, rows, cols);
	}
	else {
		answer_matrix = SqMatrixMultiply(matrix, rows, cols);
	}
	PrintMatrix(answer_matrix, rows, rows);
	for (int i = 0;i < rows;++i) {
		delete[] matrix[i];
		delete[] answer_matrix[i];
	}
	delete[] matrix;
	delete[] answer_matrix;
}

