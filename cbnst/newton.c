#include <stdio.h>
#include <math.h>

double f(double x)
{
    return 6 * x * x + 11 * x - 35;
}

double f0(double x)
{
    return 12 * x + 11;
}

int main()
{
    double a, x;

    // calculating tolerance
    int noDigits = 4;
    double t = 0.5 * pow(10.0, -noDigits);

    // input
    printf("Enter initial approximation:: ");
    scanf("%lf", &a);

    printf("x_i\t| f(x_i)\n");
    while (1)
    {
        x = a - (f(a) / f0(a));
        printf("%lf\t| %lf\n", x, f(x));
        if (f(x) == 0)
        {
            printf("Result :: %lf", x);
            break;
        }
        else if (fabs(x - a) < t)
        {
            printf("Result:: %lf within %lf tolerance.", x, t);
            break;
        }
        a = x;
    }
    return 0;
}