#include <stdio.h>
#include <stdlib.h>

// создаём структуру узла
typedef struct node {
    int data;
    struct node *next;
}LIST;

// функция добавляет новый элемент в начало списка
LIST* creater(LIST** top, int data) {
    LIST* fresh = (LIST*)malloc(sizeof(LIST)); // выделяем память под элемент
    fresh->data = data; // пихаеи данные
    fresh->next = *top; // указатель на следующий элемент
    *top = fresh; // теперь указатель на новый элемент другой
}

// функция вывода списка
void print(LIST* top) {
    LIST* ptr = top;
    while (ptr) { // пока указатель на элемент структуры не равег NULL
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// функция разделения списка на 2 половины
void split(LIST* full, LIST** first, LIST** sec) {
    if (full == NULL || full->next == NULL) { // если длина 1 или 0, нечего разделять
        *first = full;
        *sec = NULL;
        return;
    }

    LIST* slow = full; // подсписок из половины
    LIST* fast = full->next; // подсписок из второй половины

    while (fast != NULL) { // fast движется вдвое быстрее slow
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // slow находится ровно перед серединой списка
    *first = full; // записываем начало переписываем в первый список
    *sec = slow->next; // середину записываем во второй
    slow->next = NULL; // удаляем связь между списками

}

// функция ообъединения двух списков
LIST* all(LIST* a, LIST* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    LIST* res = NULL; // создаём указатель на результат

    if (a->data <= b->data) {
        res = a;
        res->next = all(a->next, b); // рекурсивно выбираем из двух списков меньший элемент
    }

    else {
        res = b;
        res->next = all(a, b->next);
    }

    return res;
}

// функция сортировки слиянием
void sort(LIST** top) {
    // если длина 1 или 0, нечего сортировать
    if (*top == NULL || (*top)->next == NULL) {
        return;
    }

    LIST* a, *b;

    split(*top, &a, &b); // разделяем список на 2
    // сортируем каждый список поочереди
    sort(&a);
    sort(&b);

    *top = all(a, b); // объеденяем списки
}

int main()
{
    FILE* in = fopen("input.txt", "r");
    FILE* out = fopen("output.txt", "w");

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
