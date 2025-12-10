#include "Microchip.h"
#include <iomanip>


template <typename TVoltage, typename TPinCount>
Microchip<TVoltage, TPinCount>::Microchip()
    : name_(""), pinCount_(TPinCount()), voltage_(TVoltage())
{
}

template <typename TVoltage, typename TPinCount>
Microchip<TVoltage, TPinCount>::Microchip(const std::string& name,
                                          TPinCount pinCount,
                                          TVoltage voltage)
    : name_(name), pinCount_(pinCount), voltage_(voltage)
{
}

template <typename TVoltage, typename TPinCount>
Microchip<TVoltage, TPinCount>::~Microchip()
{
    // Для демонстрації деструктор можна залишити порожнім
}

template <typename TVoltage, typename TPinCount>
const std::string& Microchip<TVoltage, TPinCount>::getName() const
{
    return name_;
}

template <typename TVoltage, typename TPinCount>
TPinCount Microchip<TVoltage, TPinCount>::getPinCount() const
{
    return pinCount_;
}

template <typename TVoltage, typename TPinCount>
TVoltage Microchip<TVoltage, TPinCount>::getVoltage() const
{
    return voltage_;
}

template <typename TVoltage, typename TPinCount>
void Microchip<TVoltage, TPinCount>::setName(const std::string& name)
{
    name_ = name;
}

template <typename TVoltage, typename TPinCount>
void Microchip<TVoltage, TPinCount>::setPinCount(TPinCount pinCount)
{
    pinCount_ = pinCount;
}

template <typename TVoltage, typename TPinCount>
void Microchip<TVoltage, TPinCount>::setVoltage(TVoltage voltage)
{
    voltage_ = voltage;
}

template <typename TVoltage, typename TPinCount>
void Microchip<TVoltage, TPinCount>::print() const
{
    std::cout << "=== Мікросхема (основний шаблон) ===\n";
    std::cout << "Назва/маркування: " << name_ << "\n";
    std::cout << "Кількість виводів: " << pinCount_ << "\n";
    std::cout << "Напруга живлення: " << voltage_ << " В\n";
    std::cout << "-------------------------------------\n";
}


template <typename TPinCount>
Microchip<double, TPinCount>::Microchip()
    : name_(""), pinCount_(TPinCount()), voltage_(0.0)
{
}

template <typename TPinCount>
Microchip<double, TPinCount>::Microchip(const std::string& name,
                                        TPinCount pinCount,
                                        double voltage)
    : name_(name), pinCount_(pinCount), voltage_(voltage)
{
}

template <typename TPinCount>
Microchip<double, TPinCount>::~Microchip()
{
}

template <typename TPinCount>
const std::string& Microchip<double, TPinCount>::getName() const
{
    return name_;
}

template <typename TPinCount>
TPinCount Microchip<double, TPinCount>::getPinCount() const
{
    return pinCount_;
}

template <typename TPinCount>
double Microchip<double, TPinCount>::getVoltage() const
{
    return voltage_;
}

template <typename TPinCount>
void Microchip<double, TPinCount>::setName(const std::string& name)
{
    name_ = name;
}

template <typename TPinCount>
void Microchip<double, TPinCount>::setPinCount(TPinCount pinCount)
{
    pinCount_ = pinCount;
}

template <typename TPinCount>
void Microchip<double, TPinCount>::setVoltage(double voltage)
{
    voltage_ = voltage;
}

template <typename TPinCount>
void Microchip<double, TPinCount>::print() const
{
    std::cout << "=== Мікросхема (часткова спец. TVoltage = double) ===\n";
    std::cout << "Назва/маркування: " << name_ << "\n";
    std::cout << "Кількість виводів: " << pinCount_ << "\n";

    // Специфічна поведінка: форматований вивід double
    std::cout << "Напруга живлення: ";
    std::cout.setf(std::ios::fixed);
    std::cout << std::setprecision(3) << voltage_ << " В\n";
    std::cout.unsetf(std::ios::floatfield);
    std::cout << "-------------------------------------\n";
}

Microchip<int, int>::Microchip()
    : name_(""), pinCount_(0), voltage_(0)
{
}

Microchip<int, int>::Microchip(const std::string& name,
                               int pinCount,
                               int voltage)
    : name_(name), pinCount_(pinCount), voltage_(voltage)
{
}

Microchip<int, int>::~Microchip()
{
}

const std::string& Microchip<int, int>::getName() const
{
    return name_;
}

int Microchip<int, int>::getPinCount() const
{
    return pinCount_;
}

int Microchip<int, int>::getVoltage() const
{
    return voltage_;
}

void Microchip<int, int>::setName(const std::string& name)
{
    name_ = name;
}

void Microchip<int, int>::setPinCount(int pinCount)
{
    pinCount_ = pinCount;
}

void Microchip<int, int>::setVoltage(int voltage)
{
    voltage_ = voltage;
}

void Microchip<int, int>::print() const
{
    std::cout << "=== Мікросхема (повна спец. <int,int>) ===\n";
    std::cout << "Цифрова ІМС: " << name_ << "\n";
    std::cout << "Кількість виводів: " << pinCount_ << "\n";
    std::cout << "Напруга живлення (ціла): " << voltage_ << " В\n";
    std::cout << "-------------------------------------\n";
}

// Основний шаблон для комбінації <float, int>
template class Microchip<float, int>;

// Часткова спеціалізація для <double, unsigned int>
template class Microchip<double, unsigned int>;
