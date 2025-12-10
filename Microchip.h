#ifndef MICROCHIP_H
#define MICROCHIP_H

#include <string>
#include <iostream>


template <typename TVoltage, typename TPinCount>
class Microchip
{
private:
    std::string name_;     // Назва / маркування
    TPinCount   pinCount_; // Кількість виводів
    TVoltage    voltage_;  // Напруга живлення

public:
    // Конструктор за замовчуванням
    Microchip();

    // Параметризований конструктор
    Microchip(const std::string& name, TPinCount pinCount, TVoltage voltage);

    // Деструктор
    ~Microchip();

    // Методи доступу (getters)
    const std::string& getName() const;
    TPinCount          getPinCount() const;
    TVoltage           getVoltage() const;

    // Методи-мутатори (setters)
    void setName(const std::string& name);
    void setPinCount(TPinCount pinCount);
    void setVoltage(TVoltage voltage);


    void print() const;
};

template <typename TPinCount>
class Microchip<double, TPinCount>
{
private:
    std::string name_;
    TPinCount   pinCount_;
    double      voltage_;

public:
    Microchip();
    Microchip(const std::string& name, TPinCount pinCount, double voltage);
    ~Microchip();

    const std::string& getName() const;
    TPinCount          getPinCount() const;
    double             getVoltage() const;

    void setName(const std::string& name);
    void setPinCount(TPinCount pinCount);
    void setVoltage(double voltage);

    void print() const;
};

template <>
class Microchip<int, int>
{
private:
    std::string name_;
    int         pinCount_;
    int         voltage_;

public:
    Microchip();
    Microchip(const std::string& name, int pinCount, int voltage);
    ~Microchip();

    const std::string& getName() const;
    int                getPinCount() const;
    int                getVoltage() const;

    void setName(const std::string& name);
    void setPinCount(int pinCount);
    void setVoltage(int voltage);

    void print() const;
};

#endif
