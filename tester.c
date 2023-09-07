#include <stdio.h>
#include "tester.h"

int tester_mode() {
    FILE *file;
    char name[] = "test.txt";
    if ((file = fopen(name, "r")) == NULL)
    {
      printf("Не удалось открыть файл");
      getchar();
      return 0;
    }

    test(file);
    
    fclose(file);
    getchar();
    return 0;
}

void test(FILE* stream)
{
    struct Coeffs EqCoefficients, TestCoefficients;
    int n_tests = 0;
    fscanf(stream, "%d", &n_tests);
    for (n_tests; n_tests > 0; n_tests--)
    {
        clear_struct(&EqCoefficients);
        fscanf(stream, "%g %g %g", &EqCoefficients.a, &EqCoefficients.b, &EqCoefficients.c);
        fscanf(stream, "%d %g %g", &TestCoefficients.n_roots, &TestCoefficients.x1, &TestCoefficients.x2);
        
        solve(&EqCoefficients);

        switch (equal_answers(&EqCoefficients, &TestCoefficients))
        {
            case 1:
                printf("Прошёл\n");
                break;
            case 0:
                printf("Ожидалось: %d %g %g ", TestCoefficients.n_roots, TestCoefficients.x1, TestCoefficients.x2);
                printf("Получилось: %d %g %g\n", EqCoefficients.n_roots, EqCoefficients.x1, EqCoefficients.x2);
                break;
            default:
                printf("Чё-то не так со сравнением.");
                break;

        }
    }
}

int equal_answers(struct Coeffs* p_EqCoefficients, struct Coeffs* p_TestCoefficients)
{
    if ((p_EqCoefficients->n_roots == p_TestCoefficients->n_roots) && (p_EqCoefficients->x1 == p_TestCoefficients->x1) && (p_EqCoefficients->x2 == p_TestCoefficients->x2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

