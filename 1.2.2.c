#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief проверяет корректность ввода
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
double arith_mean_cubes(const double a, const double b);

/**
 * @brief Вычисляет среднее геометрическое модулей двух чисел.
 *
 * Формула: sqrt(|a| * |b|).
 *
 * @param a Первое число.
 * @param b Второе число.
 * @return Среднее геометрическое модулей чисел a и b.
 */
double geom_mean_abs(const double a, const double b);

/**
 * @brief Точка входа в программу.
 *
 * Считывает два числа с клавиатуры (по одному), вычисляет среднее
 * арифметическое их кубов и среднее геометрическое их модулей,
 * выводит результаты.
 *
 * @return 0 при успешном завершении.
 */
int main() {
    printf("Введите первое число: ");
    const double a = GetValidValue();

    printf("Введите второе число: ");
    const double b = GetValidValue();

    printf("Среднее арифметическое кубов: %.6f\n", arith_mean_cubes(a, b));
    printf("Среднее геометрическое модулей: %.6f\n", geom_mean_abs(a, b));

    return 0;
}

double GetValidValue() {
    double value = 0.0;

    while (scanf("%lf", &value) != 1) {
        if (feof(stdin)) {
            fprintf(stderr, "Ошибка: ввод прерван.\n");
            exit(1);
        }

        /* очищаем буфер от некорректных символов */
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
        }

        printf("Ошибка: нужно ввести число. Повторите ввод: ");
    }

    return value;
}

double arith_mean_cubes(const double a, const double b) {
    return (pow(a, 3) + pow(b, 3)) / 2.0;
}

double geom_mean_abs(const double a, const double b) {
    return sqrt(fabs(a) * fabs(b));
}
