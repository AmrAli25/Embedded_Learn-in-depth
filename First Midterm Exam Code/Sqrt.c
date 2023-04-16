#include "stdio.h"


double Sqrt(int num) {
    double x0 = num / 2.0; // Initial guess
    double x1 = 0;
    while (1) {
        x1 = 0.5 * (x0 + num / x0); // Newton-Raphson formula
        if (x0 == x1)
            break;
        x0 = x1;
    }
    return x1;
}
