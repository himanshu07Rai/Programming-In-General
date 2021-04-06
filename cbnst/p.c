#include <stdio.h>
#include <string.h>

int main()
{
    char a[1000];
    int i;
    printf("Enter the expression:: ");
    scanf("%s", a);

    char b[1000];
    for (i = 0; i <= strlen(a); i++)
    {
        if (a[i] == ' ')
            continue;
        b[i] = a[i];
    }

    int coeff[100];
    int degree[100];
    int n = strlen(b);
    int count = 0;
    int deg = 0;
    int coef = 0;

    for (i = 0; i < n; i++)
    {

        if (b[i] >= '0' && b[i] <= '9')
        {
            coef = coef * 10 + (b[i] - '0');
        }
        else if (b[i] == 'x')
        {
            if (coef == 0)
                coeff[count] = 1;
            else
                coeff[count] = coef;
            coef = 0;
        }
        else if (b[i] == '+')
        {
            if (coef == 0)
                degree[count] = 1;
            else
                degree[count] = coef;
            coef = 0;
            count++;
        }
    }
    coeff[count] = coef;
    degree[count] = 0;
    count++;
    for (i = 0; i < count; i++)
    {
        printf("deg:: %d coeff:: %d\n", degree[i], coeff[i]);
    }

    return 0;
}