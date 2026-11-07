#include <stdio.h>
#include <locale.h>
#include <math.h>

#define PI 3.14159265358979323846

int z_0_1(int count, char znak1);
int z_0_2(int count, char znak1, char znak2);
int z_0_3(int count, char znak1);

int z_1(int n, int m);
long long z_1A(int stepen);
double z_2(double x); 
double z_3();

int main() {
    setlocale(LC_CTYPE, "ru_RU.UTF-8");

    //Задание 0
    printf("Задание 0\n");
    for (int start = 1; start <= 10; start++)
        putchar('*');
    printf("\n\n");

    int count;
    char znak1, znak2;

    printf("Введите количество символов: ");
    if (scanf("%d", &count) != 1) return 1;

    printf("Введите основной знак: ");
    if (scanf(" %c", &znak1) != 1) return 1;

    printf("Введите второй знак: ");
    if (scanf(" %c", &znak2) != 1) return 1;

    printf("\n1) В начале и в конце символ '+': \n");
    z_0_1(count, znak1);

    printf("\n2) Полстроки одним знаком, вторую половину другим: \n");
    z_0_2(count, znak1, znak2);

    printf("\n3) После каждого знака восклицательный знак '!': \n");
    z_0_3(count, znak1);

    //Задание 1
    printf("\nЗадание 1\n");
    int n, m;
    printf("Введите n и m (через пробел, n <= m): ");
    if (scanf("%d %d", &n, &m) != 2) return 1;

    if (m < n) {
        printf("Ошибка: конечное значение m должно быть >= n\n");
    }
    else {
        int sum_res = z_1(n, m);
        printf("Итоговая сумма от %d до %d равна: %d\n", n, m, sum_res);
    }

    //Задание 1А
    printf("\nЗадание 1А\n");
    int stepen;
    printf("Введите степень m (от 0 до 62): ");
    if (scanf("%d", &stepen) != 1) return 1;

    if (stepen < 0 || stepen > 62) {
        printf("Ошибка: степень должна быть в диапазоне от 0 до 62 во избежание переполнения!\n");
    }
    else {
        long long current_val = 1;
        for (int p = 0; p <= stepen; p++) {
            printf("2^%2d = %5lld\n", p, current_val);
            if (p < stepen) {
                current_val *= 2;
            }
        }

        long long final_power = z_1A(stepen);
        double k_result = (double)final_power / 1024.0;
        printf("Результат из функции: %.1fK\n", k_result);
    }

    //Задание 2
    printf("\nЗадание 2\n");
    printf("Вычисляемая функция: y = x^2 + 2*pi*cos(pi*x) на отрезке [0.1; 2.5]\n");
    double h;
    printf("Введите шаг табуляции (например, 0.3): ");
    if (scanf("%lf", &h) != 1) return 1;

    //Проверяем h > 0 строго до табуляции и вывода таблицы
    if (h <= 0) {
        printf("Ошибка: шаг табуляции должен быть строго больше 0!\n");
    }
    else {
        double start = 0.1;
        double end = 2.5;
        int steps_count = 0;


        printf("\n-------------------------\n");
        printf("|   x   |      f(x)     |\n");
        printf("-------------------------\n");


        for (double x = start; x <= end + 1e-9; x += h) {

            double y = z_2(x);
            printf("| %5.2f | %13.4f |\n", x, y);
            steps_count++;
        }
        printf("-------------------------\n");
        printf("Табуляция успешно завершена. Выведено точек: %d\n", steps_count);
    }

    //Задание 3
    printf("\nЗадание 3\n");
    printf("Вычисление выражения: (1 + sin(0.1)) * (1 + sin(0.2)) * ... * (1 + sin(10))\n");
    double result_3 = z_3();
    printf("Результат вычисления: %.16f\n", result_3);

    return 0;
}

int z_0_1(int count, char znak1) {
    putchar('+');
    for (int start = 1; start <= count; start++) {
        putchar(znak1);
    }
    putchar('+');
    printf("\n");
    return 0;
}

int z_0_2(int count, char znak1, char znak2) {
    int half = count / 2;
    for (int start = 1; start <= count; start++) {
        if (start <= half) {
            putchar(znak1);
        }
        else {
            putchar(znak2);
        }
    }
    printf("\n");
    return 0;
}

int z_0_3(int count, char znak1) {
    for (int start = 1; start <= count; start++) {
        putchar(znak1);
        putchar('!');
    }
    printf("\n");
    return 0;
}

int z_1(int n, int m) {
    int s = 0;
    for (int i = m; i >= n; i--) {
        s += i;
    }
    return s;
}

long long z_1A(int stepen) {
    long long res = 1;
    for (int p = 0; p < stepen; p++) {
        res *= 2;
    }
    return res;
}

double z_2(double x) {
    return x * x + 2.0 * PI * cos(PI * x);
}

double z_3() {
    double p = 1.0;
    for (int i = 1; i <= 100; i++) {
        double radian = i / 10.0;
        p *= (1.0 + sin(radian));
    }
    return p;
}
