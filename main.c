#include <stdio.h>
#include "solver.h"
#include "tester.h"

int main()
{
    switch (choise_mode())
    {
    case 1:
        tester_mode();
        break;
    case 2:
        solve_mode();
        break;
    default:
        break;
    }
    return 0;
}