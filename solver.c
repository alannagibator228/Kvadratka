#include <stdio.h>
#include <math.h>
#include "solver.h"

int choise_mode()
{
    int number_of_mode = 0;
    printf("Введи номер желаемого режима: 1) тест 2) решение. Для выхода нажми q\n");
    while (scanf("%d", &number_of_mode) != 1 || number_of_mode != 1 && number_of_mode != 2)
    {
        if (getchar() == 'q')
        {
            return CLOSE_PROGRAM;
        }
        while (getchar() != '\n') {};

        printf("Нормально напиши\n");   
    }

    return number_of_mode;
}

int scan_coeff(struct Coeffs* p_EqCoefficients)
{
    while (scanf("%g %g %g", &(p_EqCoefficients->a), &(p_EqCoefficients->b), &(p_EqCoefficients->c)) != 3)
    {
        if (getchar() == 'q')
        {
            return CLOSE_PROGRAM;
        }
        while (getchar() != '\n') {};

        printf("Нормально напиши\n");   
    }
    return 0;
}

void solve(struct Coeffs* p_EqCoefficients)
{
    if (p_EqCoefficients->a == 0)
    {
        solve_linear(p_EqCoefficients);
    }
    else
    {
        solve_square(p_EqCoefficients);
    }
}

int solve_linear(struct Coeffs* p_EqCoefficients)
{
    if (p_EqCoefficients->b == 0 && p_EqCoefficients->c == 0)
    {
        p_EqCoefficients->n_roots = MNOGO;
        return MNOGO;
    }
    else if (p_EqCoefficients->b == 0)
    {
        p_EqCoefficients->n_roots = ZERO_ROOTS;
        return ZERO_ROOTS;
    }
    
    else
    {
        if (p_EqCoefficients->c != 0)
        {
            p_EqCoefficients->x1 = -p_EqCoefficients->c / p_EqCoefficients->b;
            p_EqCoefficients->n_roots = ONE_ROOTS;
            return ONE_ROOTS;
        }
        else
        {
            p_EqCoefficients->x1 = 0;
            p_EqCoefficients->n_roots = ONE_ROOTS;
            return ONE_ROOTS;
        }
    }
}

int solve_square(struct Coeffs* p_EqCoefficients)
{
    p_EqCoefficients->discriminant = p_EqCoefficients->b * p_EqCoefficients->b - 4 * p_EqCoefficients->a * p_EqCoefficients->c;
    
    if (p_EqCoefficients->discriminant < 0)
    {
        p_EqCoefficients->n_roots = ZERO_ROOTS;
        return ZERO_ROOTS;
    }
    else if (p_EqCoefficients->discriminant == 0)
    {
        if (p_EqCoefficients->b != 0)
        {
            p_EqCoefficients->x1 = -p_EqCoefficients->b / (p_EqCoefficients->a * 2);
            p_EqCoefficients->n_roots = ONE_ROOTS;
            return ONE_ROOTS;
        }
        else
        {
            p_EqCoefficients->x1 = 0;
            p_EqCoefficients->n_roots = ONE_ROOTS;
            return ONE_ROOTS;
        }
        
    }
    else
    {
        p_EqCoefficients->discriminant = sqrt(p_EqCoefficients->discriminant);
        p_EqCoefficients->x1 = (-p_EqCoefficients->b - p_EqCoefficients->discriminant)/(p_EqCoefficients->a * 2);
        p_EqCoefficients->x2 = (-p_EqCoefficients->b + p_EqCoefficients->discriminant)/(p_EqCoefficients->a * 2);
        p_EqCoefficients->n_roots = TWO_ROOTS;
        return TWO_ROOTS;
    }

}

void print_roots(struct Coeffs* p_EqCoefficients)
{
    switch (p_EqCoefficients->n_roots)
    {
    case ZERO_ROOTS:
        printf("Корней нет\n");
        break;
    case ONE_ROOTS:
        printf("Один корень:\n%g\n", p_EqCoefficients->x1);
        break;
    case TWO_ROOTS:
        printf("Два корня:\n%g\n%g\n", p_EqCoefficients->x1, p_EqCoefficients->x2);
        break;
    case MNOGO:
        printf("Корней бесконечно\n");
        break;
    default:
        printf("Какая-то хуета с количеством корней\n");
        break;
    }
}

int solve_mode()
{
    struct Coeffs EqCoefficients;
    int closer_code = 0;
    while (1)
    {
        clear_struct(&EqCoefficients);
        printf("Введи коэффициенты уравнения. Для выхода нажми q\n");
        closer_code = scan_coeff(&EqCoefficients);
        if (closer_code == CLOSE_PROGRAM)
        {
           return 0;
        }
        solve(&EqCoefficients);
        print_roots(&EqCoefficients);
    }
}

void clear_struct(struct Coeffs* p_EqCoefficients)
{
    p_EqCoefficients->a = 0;
    p_EqCoefficients->b = 0;
    p_EqCoefficients->c = 0;
    p_EqCoefficients->discriminant = 0;
    p_EqCoefficients->n_roots = 0;
    p_EqCoefficients->x1 = 0;
    p_EqCoefficients->x2 = 0;
}