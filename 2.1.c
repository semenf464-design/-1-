#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/** Вычисляемая формула. */
typedef enum {
    FACE_AREA = 1,    /**< площадь грани */
    SURFACE_AREA = 2, /**< площадь полной поверхности */
    VOLUME = 3        /**< объём */
} Formula;

/**
 * @brief Запрашивает у пользователя номер формулы.
 *
 * Если введено не число, выводит сообщение об ошибке и завершает программу.
 *
 * @return Выбранная формула.
 */
Formula GetFormula();

/**
 * @brief Запрашивает у пользователя длину ребра куба.
 *
 * Если введено не число или число не положительно,
 * выводит сообщение об ошибке и завершает программу.
 *
 * @return Корректное введённое значение (длина ребра > 0).
 */
double GetValidValue();

/**
 * @brief Вычисляет значение выбранной формулы.
 *
 * Если формула не существует, выводит сообщение об ошибке
 * и завершает программу.
 *
 * @param formula Выбранная формула.
 * @param a Длина ребра куба.
 * @return Результат вычисления выбранной формулы.
 */
double calculate(const Formula formula, const double a);

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
 * Считывает номер формулы и длину ребра куба, вычисляет выбранную
 * величину и выводит результат.
 *
 * @return 0 при успешном завершении.
 */
int main() {
    printf("Выберите формулу:\n");
    printf("%d - площадь грани\n", FACE_AREA);
    printf("%d - площадь полной поверхности\n", SURFACE_AREA);
    printf("%d - объём\n", VOLUME);
    printf("Ваш выбор: ");
    const Formula formula = GetFormula();

    printf("Введите длину ребра куба: ");
    const double a = GetValidValue();

    printf("Результат: %.6f\n", calculate(formula, a));

    return 0;
}

Formula GetFormula() {
    int choice = 0;

    /* scanf возвращает количество успешно считанных значений */
    if (scanf("%d", &choice) != 1) {
        printf("Ошибка: нужно ввести номер формулы.\n");
        exit(1);
    }

    return (Formula)choice;
}

double GetValidValue() {
    double value = 0.0;

    if (scanf("%lf", &value) != 1) {
        printf("Ошибка: нужно ввести число.\n");
        exit(1);
    }

    if (value <= 0.0) {
        printf("Ошибка: длина ребра должна быть положительной.\n");
        exit(1);
    }

    return value;
}

double calculate(const Formula formula, const double a) {
    switch (formula) {
        case FACE_AREA:
            return face_area(a);
        case SURFACE_AREA:
            return surface_area(a);
        case VOLUME:
            return volume(a);
        default:
            printf("Ошибка: такой формулы нет.\n");
            exit(1);
    }
}

double face_area(const double a) {
    return pow(a, 2);
}

double surface_area(const double a) {
    return 6.0 * pow(a, 2);
}

double volume(const double a) {
    return pow(a, 3);
}
