#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int i, j, k, x, y, z, n, num;
    printf("\nEnter number of equations : ");
    scanf("%d", &num);
    int arr[50][50];
    char str[21];
    int sum;
    for (i = 0; i < num; i++)
    {
        printf("Enter equation %d : ", i + 1);
        scanf("%s", str);
        x = 0, y = 0, z = 0, n = 1;
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
                x = 1;
                if (sum == 0)
                    sum = 1;
                if (n == -1)
                {
                    arr[i][0] = sum * -1;
                }
                else
                    arr[i][0] = sum;
                n = 1;
                sum = 0;
            }
            else if (str[k] == 'y')
            {
                y = 1;
                if (sum == 0)
                    sum = 1;
                if (n == -1)
                {
                    arr[i][1] = sum * -1;
                }
                else
                    arr[i][1] = sum;
                n = 1;
                sum = 0;
            }
            else if (str[k] == 'z')
            {
                z = 1;
                if (sum == 0)
                    sum = 1;
                if (n == -1)
                {
                    arr[i][2] = sum * -1;
                }
                else
                    arr[i][2] = sum;
                n = 1;
                sum = 0;
            }
            else if (str[k] == 'x' && str[k + 1] == '=' || str[k] == 'y' && str[k + 1] == '=' || str[k] == 'z' && str[k + 1] == '=')
            {
                arr[i][3] = 0;
                break;
            }
            else if (str[k] >= '0' && str[k] <= '9')
            {
                sum = sum * 10 + (str[k] - '0');
            }
            else if (str[k] == '=')
            {
                if (n == -1)
                {
                    arr[i][3] = sum * -1;
                }
                else
                    arr[i][3] = sum;
                break;
            }
        }
        if (x == 0)
            arr[i][0] = 0;
        if (y == 0)
            arr[i][1] = 0;
        if (z == 0)
            arr[i][2] = 0;
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}