#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/** Число миллиметров в одном метре (для перевода x в метры). */
#define MM_IN_METER 1000.0

/**
 * @brief Вычисляет потенциальную энергию растянутой пружины.
 *
 * Растяжение переводится из миллиметров в метры, затем
 * используется формула E = k * x^2 / 2.
 *
 * @param k Коэффициент жёсткости пружины, Н/м.
 * @param x_mm Растяжение пружины, мм.
 * @return Потенциальная энергия пружины, Дж.
 */
double spring_energy(const double k, const double x_mm);

/**
 * @brief Считывает вещественное число с клавиатуры.
 *
 * Выводит приглашение к вводу и проверяет, что введено число.
 * При ошибке выводит сообщение в stderr.
 *
 * @param prompt Приглашение к вводу.
 * @param name Название величины для сообщения об ошибке.
 * @param value Адрес ячейки памяти (переменной) для результата.
 * @return true, если число считано успешно, иначе false.
 */
bool read_double(const char *prompt, const char *name, double *value);

/**
 * @brief Проверяет корректность растяжения пружины.
 *
 * Если растяжение отрицательно, выводит сообщение об ошибке в stderr
 * и сразу завершает программу с кодом 1.
 *
 * @param x_mm Растяжение пружины, мм.
 */
void check_stretch(const double x_mm);

/**
 * @brief Проверяет корректность коэффициента жёсткости.
 *
 * Если жёсткость не положительна, выводит сообщение об ошибке в stderr
 * и сразу завершает программу с кодом 1.
 *
 * @param k Коэффициент жёсткости, Н/м.
 */
void check_stiffness(const double k);

/**
 * @brief Точка входа в программу.
 *
 * Считывает растяжение пружины в миллиметрах и коэффициент жёсткости
 * в Н/м, вычисляет потенциальную энергию и выводит результат.
 *
 * @return 0 при успешном завершении, 1 при ошибке ввода или некорректных данных.
 */
int main() {
    double x_mm = 0.0; /* растяжение пружины, мм */
    double k = 0.0;    /* коэффициент жёсткости, Н/м */

    /* Ввод данных с проверкой, что введены числа */
    if (!read_double("Введите растяжение пружины x, мм: ", "x", &x_mm)) {
        return 1;
    }
    if (!read_double("Введите коэффициент жёсткости k, Н/м: ", "k", &k)) {
        return 1;
    }

    /* Проверка физического смысла введённых значений
       (при ошибке программа завершается внутри функций) */
    check_stretch(x_mm);
    check_stiffness(k);

    /* Расчёт и вывод результата */
    printf("Потенциальная энергия пружины: %.6f Дж\n", spring_energy(k, x_mm));

    return 0;
}

double spring_energy(const double k, const double x_mm) {
    return k * pow(x_mm / MM_IN_METER, 2) / 2.0;
}

bool read_double(const char *prompt, const char *name, double *value) {
    printf("%s", prompt);
    if (scanf("%lf", value) != 1) {
        fprintf(stderr, "Ошибка: %s должно быть числом.\n", name);
        return false;
    }
    return true;
}

void check_stretch(const double x_mm) {
    if (x_mm < 0.0) {
        fprintf(stderr, "Ошибка: растяжение не может быть отрицательным.\n");
        exit(1);
    }
}

void check_stiffness(const double k) {
    if (k <= 0.0) {
        fprintf(stderr, "Ошибка: жёсткость должна быть положительной.\n");
        exit(1);
    }
}
