#include <stdio.h>
#include <stdlib.h>

// создаём структуру узла
typedef struct node {
    int data;
    struct node *next;
}LIST;

// функция добавляет новый элемент и возвращает указатель на него
LIST* creater(LIST* top, int data) {
    LIST* fresh = malloc(sizeof(LIST));
    fresh->data = data;
    fresh->next = top;
    return fresh;
}

// функция удаляет элемент и возвращает указатель на следующий
/*LIST* del(LIST* top) {
    if (top == NULL) return top;
    LISE* next = top->next;
    free(top);
    return next
}
int sort(LIST* *a, int n) {
    int ser = n / 2; // середина последовательности
    if (n % 2 == 1) ser++;

    int g = 1;// шаг

    // выделяем помять
    int *c = (int*)calloc(n, sizeof(int));
    int step = 0;

    while (g < n) {
        step = g;
        int i = 0, j = ser, k = 0;
        while (step <= ser) {
            while ((i < step) && (j < n) && (j < (ser + step))) {// ???
                if (a[i] < a[j]) {
                    c[k++] = a[i++];
                }
                else {
                    c[k++] = a[j++];
                }
            }
            while (i < step) {
                c[k++] = a[i++];
            }
            while ((j < (ser + step)) && (j < n)) {
                c[k++] = a[j++];
            }
            step += g;
        }
        g *= 2;

        for (i = 0; i < n; ++i) {
            a[i] = c[i]
        }
    }

}*/

int main()
{
    FILE* in = fopen("input.txt", "r");
    FILE* out = fopen("output.txt", "w");
    char str[] = "Function fputc() in action.";
    int i = 0;
    int tem = 0;

    if (in == NULL) return 1;
    if (out == NULL) return 1;

    fscanf(in, "%d", &tem);
    printf("%d", tem);

    i = 0;

    fclose(in);
    fclose(out);

    return 0;
}
