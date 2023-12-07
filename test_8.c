// Ратова Ярослава      группа 105      задание 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ABS(x) (((x) > 0) ? (x) : -(x))
#define MIN(x, y) ((x > y) ? y : x)
#define MAX(x, y) ((x > y) ? x : y)

// сумма
void sum(int a[], int b[], int mx) {
    int res[10002];
    int i = 0;
    int tem = 0;

    while (i < mx) {
        res[mx - i] = (a[mx - i - 1] + b[mx - i - 1] + tem) % 10;
        i++;
        tem = (a[mx - i] + b[mx - i] + tem) / 10;
    }
    res[0] = tem;
    for (i = res[0] == 0 ? 1 : 0; i < mx + 1; i++) printf("%d", res[i]);
}

// разность
void dif(int a[], int b[], int mx) {
    int res[10002] = {0};
    int i = 0, j = 0;
    int tem = 0, flag  = 0;

    while (i < mx) {
        if (a[i] > b[i]) {
            while (j < mx) {
                if (a[mx - j - 1] >= b[mx - j - 1]) res[mx - j - 1] = a[mx - j - 1] - b[mx - j - 1];
                else {
                    res[mx - j - 1] = a[mx - j - 1] - b[mx - j - 1] + 10;
                    a[mx - j - 2] -= 1;
                }
                j++;
            }
            flag = 1;
            break;
        }
        else if(b[i] > a[i]) {
            while (j < mx) {
                if (b[mx - j - 1] >= a[mx - j - 1]) res[mx - j - 1] = b[mx - j - 1] - a[mx - j - 1];
                else {
                    res[mx - j - 1] = b[mx - j - 1] - a[mx - j - 1] + 10;
                    b[mx - j - 2] -= 1;
                }
                j++;
            }
            for (j = 0; j < mx; j++) {
                if (res[j] != 0){
                    res[j] = -res[j];
                    break;
                }
            }
            flag = 1;
            break;
        }
        i++;
    }
    if (flag == 0) {
        printf("0");
        return;
    }
    for (i = 0; i < mx; i++){
            if (res[i] != 0) flag = 0;
            if (flag == 0) printf("%d", res[i]);

    }
}

// умножение
void mult(int a[], int b[], int mx) {
    
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

    dif(a, b, mx);
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
