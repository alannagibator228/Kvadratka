
#ifndef SOLVER_H
#define SOLVER_H

#define CLOSE_PROGRAM 333

enum N_roots{
    ZERO_ROOTS = 0,
    ONE_ROOTS = 1,
    TWO_ROOTS = 2,
    MNOGO = 3
};

enum Equal_coeffs{
    YES,
    NO
};

struct Coeffs
{
    float a;
    float b;
    float c;
    int n_roots;
    float x1;
    float x2;
    float discriminant;
};

int choise_mode();

int scan_coeff(struct Coeffs* p_EqCoefficients);
void solve(struct Coeffs* p_EqCoefficients);
int solve_linear(struct Coeffs* p_EqCoefficients);
int solve_square(struct Coeffs* p_EqCoefficients);
void print_roots(struct Coeffs* p_EqCoefficients);
int solve_mode();
void clear_struct(struct Coeffs* p_EqCoefficients);



#endif