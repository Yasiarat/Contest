// ������ ��������   ������ 105    ������� 22
#include <stdio.h>

int main(void) {
    // ������ ���������� ��� ���������
    int x = 0;
    int y = 0;
    scanf("%d", &x);
    scanf("%d", &y);
    // ������ ����������� �������������� (��� ��������)
    x = (x >= 0) ? x : -x;
    y = (y >= 0) ? y : -y;
    // ���� �� ���� �� ������ ��������� �� ���������� �������� �������� ���� �� � � �, �� ����� ������. summ - ���������� ����� �����, ost - ����������
    int ost = (((x > y) ? x : y) - ((x < y) ? x : y) - 1);
    int summ = x + y - ost;
    // ����� ������������� �� 2 ���������� ������ � ���� ������� ����� 4 ����, � ���� 1 - 3
    summ += (ost / 2) * 4 + (ost % 2) * 3;
    printf("%d", summ);
    return 0;
}
