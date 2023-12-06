// Ратова Ярослава      группа 105      задание 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(x, y) ((x > y) ? y : x)
#define MAX(x, y) ((x > y) ? x : y)

int sum(int a[], int b[], int mx) {
    int res[10002];
    int i = 0;
    while (i < mx) {
        res[mx - i] += (a[mx - i - 1] + b[mx - i - 1]) % 10;
        i++;
        res[mx - i] = (a[mx - i] + b[mx - i]) / 10;
    }
    for (i = res[0] == 0 ? 1 : 0; i < mx + 1; i++) printf("%d", res[i]);
}

int main(void)
{
    int a[10001] = {0}, b[10001] = {0};
    int n = 0;
    int e_a = 0, e_b = 0;
    char str[20001];
    char ex = '0';
    int i = 0, j = 0;

    scanf("%s", str);
    n = strlen(str);

    i = 0;
    while ((str[i] <= '9') && (str[i] >= '0')) {
        a[i] = (int) str[i] - 48;
        //printf("%d", a[i]);
        i++;
    }
    e_a = i;
    ex = str[i++];
    while (str[i] != '\0') {
        b[j++] = (int) str[i] - 48;
        i++;
    }
    e_b = i - e_a - 1;

    //sum(a, b, end_a, end_b);

    int mx = MAX(e_a, e_b);

    if (mx != e_b) {
        for (i = 0; i < e_b + 1; i++) {
            b[e_a - i] = b[e_b - i];
        }
        for (i = e_a - e_b - 1; i >= 0; i--) b[i] = 0;
    }

    else if (mx != e_a){
        for (i = 0; i < e_a + 1; i++) {
            a[e_b - i] = a[e_a - i];
        }
        for (i = e_b - e_a - 1; i >= 0; i--) a[i] = 0;
    }

    sum(a, b, mx);
    /*
    for (i = 0; i < mx; i++) {
        printf("%d", a[i]);
    }
    printf("\n");
    for (i = 0; i < mx; i++) {
        printf("%d", b[i]);
    }*/
    return 0;
}
