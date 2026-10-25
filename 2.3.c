#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Запрашивает у пользователя положительное число.
 *
 * Если введено не число или число не положительно,
 * выводит сообщение об ошибке и завершает программу.
 *
 * @param name Название вводимой величины (для приглашения к вводу).
 * @return Введённое положительное число.
 */
double GetPositiveValue(const char *name);

/**
 * @brief Проверяет, можно ли построить треугольник с данными сторонами.
 *
 * Треугольник существует, если каждая сторона меньше суммы двух других.
 *
 * @param a Длина первой стороны.
 * @param b Длина второй стороны.
 * @param c Длина третьей стороны.
 * @return true, если треугольник построить можно, иначе false.
 */
bool can_build_triangle(const double a, const double b, const double c);

/**
 * @brief Проверяет, является ли треугольник остроугольным.
 *
 * Треугольник остроугольный, если квадрат каждой стороны
 * меньше суммы квадратов двух других сторон.
 *
 * @param a Длина первой стороны.
 * @param b Длина второй стороны.
 * @param c Длина третьей стороны.
 * @return true, если треугольник остроугольный, иначе false.
 */
bool is_acute(const double a, const double b, const double c);

/**
 * @brief Точка входа в программу.
 *
 * Считывает три стороны, определяет, можно ли построить треугольник,
 * и если можно, определяет, является ли он остроугольным.
 *
 * @return 0 при успешном завершении.
 */
int main() {
    const double a = GetPositiveValue("первую сторону");
    const double b = GetPositiveValue("вторую сторону");
    const double c = GetPositiveValue("третью сторону");

    if (!can_build_triangle(a, b, c)) {
        printf("Треугольник с такими сторонами построить нельзя.\n");
        return 0;
    }

    printf("Треугольник построить можно.\n");

    if (is_acute(a, b, c)) {
        printf("Треугольник остроугольный.\n");
    } else {
        printf("Треугольник не остроугольный.\n");
    }

    return 0;
}

double GetPositiveValue(const char *name) {
    double value = 0.0;

    printf("Введите %s: ", name);

    /* scanf возвращает количество успешно считанных значений */
    if (scanf("%lf", &value) != 1) {
        printf("Ошибка: нужно ввести число.\n");
        exit(1);
    }

    if (value <= 0.0) {
        printf("Ошибка: число должно быть положительным.\n");
        exit(1);
    }

    return value;
}

bool can_build_triangle(const double a, const double b, const double c) {
    return a < b + c && b < a + c && c < a + b;
}

bool is_acute(const double a, const double b, const double c) {
    return pow(a, 2) < pow(b, 2) + pow(c, 2) &&
           pow(b, 2) < pow(a, 2) + pow(c, 2) &&
           pow(c, 2) < pow(a, 2) + pow(b, 2);
}
