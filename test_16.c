// Ратова Ярослава      группа 105      задание 8
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ABS(x) ((x) > 0) ? (x) : -(x)

int run(mas, int xn, int yn, int xk, int yk) {
    if ((i / m > 0) && (mas[i - m] != 1)) mas[i - m] = -1;
    if ((i / m < n - 1) && (mas[i + m] != 1)) mas[i + m] = -1;
    if ((i % m > 0) && (mas[i - 1] != 1)) mas[i - 1] = -1;
    if ((i % m < m - 1) && (mas[i + 1] != 1)) mas[i + 1] = -1;
}

int main(void)
{
    int n = 0, xn = 0, yn = 0, xk = 0, yk = 0;
    int i = 0, j = 0;
    extern mas[][];
    scanf("%d", &n);

    int mas[n][n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            mas[i][j] = -1;
        }
    }
    mas[xn][yn] = 0;

    scanf("%d%d%d%d", &xn, &yn, xk, yk);



    return 0;
}
