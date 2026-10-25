#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Запрашивает у пользователя вещественное число.
 *
 * Если введено не число, выводит сообщение об ошибке и завершает программу.
 *
 * @return Корректное введённое значение.
 */
double GetValidValue();

/**
 * @brief Вычисляет значение кусочно-заданной функции y(x).
 *
 * Формула:
 *   y = a * sin((x^2 + 1) / 10), если a * x < 1;
 *   y = a * cos((x - 1) / 10),   если a * x >= 1.
 *
 * @param a Параметр функции.
 * @param x Аргумент функции.
 * @return Значение функции y при заданных a и x.
 */
double calc_y(const double a, const double x);

/**
 * @brief Точка входа в программу.
 *
 * Считывает значение x, вычисляет значение функции y при a = 0.3
 * и выводит результат.
 *
 * @return 0 при успешном завершении.
 */
int main() {
    const double a = 0.3;

    printf("Введите x: ");
    const double x = GetValidValue();

    printf("y = %.6f\n", calc_y(a, x));

    return 0;
}

double GetValidValue() {
    double value = 0.0;

    /* scanf возвращает количество успешно считанных значений */
    if (scanf("%lf", &value) != 1) {
        printf("Ошибка: нужно ввести число.\n");
        exit(1);
    }

    return value;
}

double calc_y(const double a, const double x) {
    if (a * x < 1.0) {
        return a * sin((x * x + 1.0) / 10.0);
    }

    return a * cos((x - 1.0) / 10.0);
}
