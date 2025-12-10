#include <iostream>
#include <limits>
#include "Microchip.h"
#include "Functions.h"


template <typename T>
void safeInput(const std::string& msg, T& value)
{
    while (true)
    {
        std::cout << msg;
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cin.clear(); // очистити стан
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Помилка: введено некоректне значення. Спробуйте ще раз.\n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
}

int main()
{
    std::string name;
    int pinsInt;
    float voltageFloat;
    double voltageDouble;
    unsigned int pinsUnsigned;


    std::cout << "=== Введення даних для аналогової мікросхеми (основний шаблон) ===\n";

    std::cout << "Введіть назву/маркування: ";
    std::getline(std::cin, name);

    safeInput("Введіть кількість виводів (int): ", pinsInt);
    safeInput("Введіть напругу живлення (float): ", voltageFloat);

    Microchip<float, int> analogChip(name, pinsInt, voltageFloat);
    analogChip.print();


    std::cout << "\n=== Введення даних для мікросхеми (часткова спец. TVoltage = double) ===\n";

    std::cout << "Введіть назву/маркування: ";
    std::getline(std::cin, name);

    safeInput("Введіть кількість виводів (unsigned int): ", pinsUnsigned);
    safeInput("Введіть напругу живлення (double): ", voltageDouble);

    Microchip<double, unsigned int> preciseChip(name, pinsUnsigned, voltageDouble);
    preciseChip.print();


    std::cout << "\n=== Введення цифрової ІМС (повна спец. <int,int>) ===\n";

    std::cout << "Введіть назву/маркування: ";
    std::getline(std::cin, name);

    safeInput("Введіть кількість виводів (int): ", pinsInt);
    safeInput("Введіть напругу живлення (int): ", pinsInt);

    Microchip<int, int> digitalChip(name, pinsInt, pinsInt);
    digitalChip.print();

    int a, b;
    safeInput("\nВведіть ціле число A: ", a);
    safeInput("Введіть ціле число B: ", b);

    std::cout << "maxValue<int>(" << a << ", " << b << ") = " << maxValue(a, b) << "\n";

    double x, y;
    safeInput("\nВведіть число X (double): ", x);
    safeInput("Введіть число Y (double): ", y);

    std::cout << "maxValue<double>(" << x << ", " << y << ") = " << maxValue(x, y) << "\n";

    return 0;
}
