#include <stdio.h>
#include <math.h>
/**
 * @brief вычисляет значение функции по заданной формуле
 * @param x - значение переменной х
 * @param y - значение переменной y
 * @param z - значение переменной z
 * @return рассчитанное значение
 */
double A(const double x, const double y, const double z);
/**
 * @brief вычисляет значение функции по заданной формуле
 * @param x - значение переменной х
 * @param y - значение переменной y
 * @param z - значение переменной z
 * @return рассчитанное значение
 */
double B(const double x, const double y, const double z);
/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    const double x =0.61;
    const double y = 0.9;
    const double z = 0.3;
    printf("A = %lf\n",A(x,y,z));
    printf("B = %lf",B(x,y,z));
    return 0;
}
double A(const double x, const double y, const double z)
{
    return (pow(z, 2 * x) + pow(y, -x) * cos((z + y) * x)) / (x + 1);
}
double B(const double x, const double y, const double z)
{
return sqrt(x * x + y) - y * y * pow(sin((x + z) / x), 3);
}
