// Ратова Ярослава   группа 105    задание 13
#include <stdio.h>

int main(void) {
    // объявляем переменные, вводим их значения
    double x = 0;
    int n = 0;
    double sin_x = 0;

    scanf("%lf", &x);
    scanf("%d", &n);
    // пробегаемся циклом от 1 до n,
    for (int i = 1; i < n + 1; ++i){
        double sqr = 1;
        int fact = 1;

        // формируем слогаемое согласно формуле
        for (int j = 1; j < 2 * i; ++j){
                sqr *= x;
                fact *= j;
            }
        // если i - чётное, слогаемое прибавляется, иначе - вычитается
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
