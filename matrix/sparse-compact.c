#include <stdio.h>

int main()
{
    int arr[20][20], b[20][20];
    int r, c;
    printf("Enter r and c : ");
    scanf("%d %d", &r, &c);
    printf("Enter elements : ");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    b[0][0] = r;
    b[0][1] = c;
    int k = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] != 0)
            {
                b[k][0] = i + 1;
                b[k][1] = j + 1;
                b[k][2] = arr[i][j];
                k++;
            }
        }
    }

    k = k-1;
    b[0][2] = k;
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
    
}