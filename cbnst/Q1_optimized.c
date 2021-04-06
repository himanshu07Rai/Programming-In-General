#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int i, j, k, n, num;
    printf("\nEnter number of equations : ");
    scanf("%d", &num);
    int arr[50][50];
    char str[21];
    int sum;
    for (i = 0; i < num; i++)
    {
        printf("Enter equation %d : ", i + 1);
        scanf("%s", str);
        n = 1;
        sum = 0;
        for (k = 0; str[k] != '\0'; k++)
        {
            if (str[k] == '-')
            {
                n = -1;
                sum = 0;
            }
            else if (str[k] == 'x')
            {
                if (sum == 0)
                    sum = 1;
                if (n == -1)
                {
                    arr[i][0] = sum * -1;
                    n = 1;
                }
                else
                    arr[i][0] = sum;
                sum = 0;
            }
            else if (str[k] == 'y')
            {
                if (sum == 0)
                    sum = 1;
                if (n == -1)
                {
                    arr[i][1] = sum * -1;
                    n = 1;
                }
                else
                    arr[i][1] = sum;
                sum = 0;
            }
            else if (str[k] == 'z')
            {
                if (sum == 0)
                    sum = 1;
                if (n == -1)
                {
                    arr[i][2] = sum * -1;
                    n = 1;
                }
                else
                    arr[i][2] = sum;
                sum = 0;
            }
            else if (str[k] >= '0' && str[k] <= '9')
            {
                sum = sum * 10 + (str[k] - '0');
            }
        }
        if (n == -1)
            arr[i][3] = -1 * sum;
        else
            arr[i][3] = sum;
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    float ae;
    int mxit;
    printf(" Eneter the allowed error and maximum number of iteration: ");
    scanf("%f ", &ae, &mxit);
    int x[3];
    for (i = 0; i < n; i++)
        x[i] = 0;
}