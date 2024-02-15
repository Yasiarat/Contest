#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ABS(x) (x >= 0) ? (x) : -(x)


int main()
{
    int n = 0, i = 0, j = 0, mn = 0;
    double tem = 0, a, b;

    scanf("%d", &n);
    double *mas;
    mas = (int*)malloc(n * sizeof(double));
    for (i = 0; i < n; i++) {
        scanf("%lf", &mas[i]);
    }

    for (i = 0; i < n; i++) {
        mn = i;
        //printf("%d", mn);

        for (j = i + 1; j < n; j++) {
            a = ABS(mas[mn]);
            b = ABS(mas[j]);
            if (a < b)
                mn = j;
        }
        tem = mas[mn];
        mas[mn] = mas[i];
        mas[i] = tem;
        //printf("%lf", mas[i]);
    }

    for (i = 0; i < n; i++) {
       printf("%lf\n", mas[i]);
    }
    free(mas);
    return 0;
}
