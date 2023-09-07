#ifndef TESTER_H
#define TESTER_H

#include "solver.h"

int tester_mode();
void test(FILE* stream);
int equal_answers(struct Coeffs* p_EqCoefficients, struct Coeffs* p_TestCoefficients);


#endif
