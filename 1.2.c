#include <stdio.h>
#include <math.h>

/**
 * @brief Вычисляет среднее арифметическое кубов двух чисел.
 *
 * Формула: (a^3 + b^3) / 2.
 *
 * @param a Первое число.
 * @param b Второе число.
 * @return Среднее арифметическое кубов чисел a и b.
 */
double arith_mean_cubes(double a, double b) {
    return (pow(a, 3) + pow(b, 3)) / 2.0;
}

/**
 * @brief Вычисляет среднее геометрическое модулей двух чисел.
 *
 * Формула: sqrt(|a| * |b|).
 *
 * @param a Первое число.
 * @param b Второе число.
 * @return Среднее геометрическое модулей чисел a и b.
 */
double geom_mean_abs(double a, double b) {
    return sqrt(fabs(a) * fabs(b));
}

/**
 * @brief Точка входа в программу.
 *
 * Считывает два числа с клавиатуры, вычисляет среднее арифметическое
 * их кубов и среднее геометрическое их модулей, выводит результаты.
 *
 * @return 0 при успешном завершении.
 */
int main() {
    double a, b;
    printf("Введите два числа через пробел: ");
    scanf("%lf %lf", &a, &b);

    printf("\nРезультаты:\n");
    printf("Среднее арифметическое кубов: %.4f\n", arith_mean_cubes(a, b));
    printf("Среднее геометрическое модулей: %.4f\n", geom_mean_abs(a, b));
    return 0;
}
