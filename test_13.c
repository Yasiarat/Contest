// ������ ��������   ������ 105    ������� 13
#include <stdio.h>

int main(void) {
    // ��������� ����������, ������ �� ��������
    double x = 0;
    int n = 0;
    double sin_x = 0;

    scanf("%lf", &x);
    scanf("%d", &n);
    // ����������� ������ �� 1 �� n,
    for (int i = 1; i < n + 1; ++i){
        double sqr = 1;
        int fact = 1;

        // ��������� ��������� �������� �������
        for (int j = 1; j < 2 * i; ++j){
                sqr *= x;
                fact *= j;
            }
        // ���� i - ������, ��������� ������������, ����� - ����������
        if (i % 2 == 1) {
            sin_x += sqr / fact;
        }
        else {
            sin_x -= sqr / fact;
        }
    }

    printf("%.6lf", sin_x);
    return 0;
}
