#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ABS(x) (x >= 0) ? (x) : -(x)
void qsortRecursive(int *mas, int size) {
    int i = 0;
    int j = size - 1;
    int mid = mas[size / 2];

    do {
        while(mas[i] < mid) {
            i++;
        }
        while(mas[j] > mid) {
            j--;
        }
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {
        qsortRecursive(&mas[i], size - i);
    }
}

int main()
{
    int n = 0, i = 0;

    scanf("%d", &n);
    double *mas;
    mas = (int*)malloc(n * sizeof(double));
    for (i = 0; i < n; i++) {
        scanf("%lf", &mas[i]);
    }

    for (i = 0; i < n; i++) {
       printf("%lf\n", mas[i]);
    }
    free(mas);
    return 0;
}
