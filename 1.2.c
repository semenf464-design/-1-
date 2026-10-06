#include <stdio.h>
#include <math.h>

/**
* @brief проверяет корретность ввода
* @return корректное полученное значение
*/
double GetValidValue();

/**
 * @brief Вычисляет среднее арифметическое кубов двух чисел.
 *
 * Формула: (a^3 + b^3) / 2.
 *
 * @param a Первое число.
 * @param b Второе число.
 * @return Среднее арифметическое кубов чисел a и b.
 */
double arith_mean_cubes(const double a, const double b) {
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
double geom_mean_abs(const double a, const double b) {
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
    double a = 0.0, b = 0.0;

    printf("Введите два числа: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        fprintf(stderr, "Ошибка: нужно ввести два числа.\n");
        return 1;
    }

    printf("Среднее арифметическое кубов: %.6f\n", mean_of_cubes(a, b));
    printf("Среднее геометрическое модулей: %.6f\n",
           geometric_mean_of_abs(a, b));

    return 0;
}
