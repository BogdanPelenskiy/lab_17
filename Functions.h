#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>


template <typename T>
const T& maxValue(const T& a, const T& b)
{
    return (a > b) ? a : b;
}


template <>
inline const double& maxValue<double>(const double& a, const double& b)
{
    std::cout << "[Спеціалізація maxValue<double>]\n";
    return (a > b) ? a : b;
}

#endif
