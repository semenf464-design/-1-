#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/**
 * @brief Запрашивает у пользователя корректное вещественное число.
 *
 * Повторяет ввод, пока не будет введено конечное число.
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
    char buffer[256];

    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            fprintf(stderr, "Ошибка: ввод прерван.\n");
            exit(1);
        }

        char *end = NULL;
        const double value = strtod(buffer, &end);

        if (end != buffer) {
            while (isspace((unsigned char)*end)) {
                end++;
            }

            if (*end == '\0' && isfinite(value)) {
                return value;
            }
        }

        printf("Ошибка: нужно ввести число. Повторите ввод: ");
    }
}

double calc_y(const double a, const double x) {
    if (a * x < 1.0) {
        return a * sin((x * x + 1.0) / 10.0);
    }

    return a * cos((x - 1.0) / 10.0);
}
