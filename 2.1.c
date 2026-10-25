#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/**
 * @brief Запрашивает у пользователя корректную длину ребра куба.
 *
 * Повторяет ввод, пока не будет введено конечное положительное число.
 *
 * @return Корректное введённое значение (длина ребра > 0).
 */
double GetValidValue();

/**
 * @brief Вычисляет площадь грани куба.
 *
 * Формула: a^2.
 *
 * @param a Длина ребра куба.
 * @return Площадь одной грани куба.
 */
double face_area(const double a);

/**
 * @brief Вычисляет площадь полной поверхности куба.
 *
 * Формула: 6 * a^2.
 *
 * @param a Длина ребра куба.
 * @return Площадь полной поверхности куба.
 */
double surface_area(const double a);

/**
 * @brief Вычисляет объём куба.
 *
 * Формула: a^3.
 *
 * @param a Длина ребра куба.
 * @return Объём куба.
 */
double volume(const double a);

/**
 * @brief Точка входа в программу.
 *
 * Считывает длину ребра куба, вычисляет площадь грани,
 * площадь полной поверхности и объём, выводит результаты.
 *
 * @return 0 при успешном завершении.
 */
int main() {
    printf("Введите длину ребра куба: ");
    const double a = GetValidValue();

    printf("Площадь грани: %.6f\n", face_area(a));
    printf("Площадь полной поверхности: %.6f\n", surface_area(a));
    printf("Объём: %.6f\n", volume(a));

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

            if (*end == '\0' && isfinite(value) && value > 0.0) {
                return value;
            }
        }

        printf("Ошибка: нужно ввести положительное число. Повторите ввод: ");
    }
}

double face_area(const double a) {
    return a * a;
}

double surface_area(const double a) {
    return 6.0 * face_area(a);
}

double volume(const double a) {
    return a * a * a;
}
