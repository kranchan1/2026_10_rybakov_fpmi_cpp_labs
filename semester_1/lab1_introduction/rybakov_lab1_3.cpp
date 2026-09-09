#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
    int num, a, b, c, d;
    std::cout << "Введите 4-значное число: ";
    std::cin >> num;
    d = num % 10;
    c = ((num - d) / 10) % 10;
    b = ((num - c * 10 - d) / 100) % 10;
    a = ((num - b * 100 - c * 10 - d) / 1000) % 10;
    if ((a == d) && (b == c)) {
        std::cout << "Число палиндром";
    }
    else {
        std::cout << "Число не палиндрром";
    }
}