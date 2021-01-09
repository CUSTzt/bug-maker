#include <math.h>
#include <stdio.h>

int main() {
    double a, b, c;
    double x1, x2;
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("now   a == %.5f  b == %.5f  c == %.5f\n", a, b, c);
    if (b * b - 4 * a * c < 0)
        printf("no solution");
    else {
        x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

        if (x1 == x2)
            printf("x1=x2=%.5f\n", x1);
        else {
            if (x1 > x2)
                printf("x1=%.5f;x2=%.5f\n", x1, x2);
            else
                printf("x1=%.5f;x2=%.5f\n", x2, x1);
        }
    }

}