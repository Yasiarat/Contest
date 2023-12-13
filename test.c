#include <stdio.h>
#include <stdlib.h>

// ”зел св€занного списка
struct Node
{
    int data;
    struct Node* next;
};

// ¬спомогательна€ функци€ дл€ печати заданного св€занного списка
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d Ч> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}

// ¬спомогательна€ функци€ дл€ вставки нового узла в начало св€занного списка
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Ѕерем два списка, отсортированных по возрастанию, и объедин€ем их узлы
// сделать один большой отсортированный список, который будет возвращен
struct Node* sortedMerge(struct Node* a, struct Node* b)
{
    // базовые случаи
    if (a == NULL) {
        return b;
    }

    else if (b == NULL) {
        return a;
    }

    struct Node* result = NULL;

    // выбираем `a` или `b` и повтор€ем
    if (a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }

    return result;
}

/*
    –азделить узлы данного списка на переднюю и заднюю половины
    и вернуть два списка, использу€ ссылочные параметры.
    ≈сли длина нечетна€, дополнительный узел должен идти в переднем списке.
    ќн использует стратегию быстрого/медленного указател€
*/
void frontBackSplit(struct Node* source, struct Node** frontRef,
                    struct Node** backRef)
{
    // если длина меньше 2, обрабатывать отдельно
    if (source == NULL || source->next == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
        return;
    }

    struct Node* slow = source;
    struct Node* fast = source->next;

    // продвигаем `fast` на два узла и продвигаем `slow` на один узел
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // `slow` находитс€ перед средней точкой в списке, поэтому разделите его на две части
    // в таком случае.
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// —ортируем заданный св€занный список, использу€ алгоритм сортировки сли€нием
void mergesort(struct Node** head)
{
    // базовый вариант Ч длина 0 или 1
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    struct Node* a;
    struct Node* b;

    // разделить `head` на подсписки `a` и `b`
    frontBackSplit(*head, &a, &b);

    // рекурсивно сортируем подсписки
    mergesort(&a);
    mergesort(&b);

    // ответ = объединить два отсортированных списка
    *head = sortedMerge(a, b);
}

int main(void)
{
    // ключи ввода
    int keys[] = { 6, 8, 4, 3, 1, 9 };
    int n = sizeof(keys)/sizeof(keys[0]);

    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        push(&head, keys[i]);
    }

    // сортируем список
    mergesort(&head);

    // печатаем отсортированный список
    printList(head);

    return 0;
}
