#include <stdio.h>

int ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return ackermann(m - 1, 1);
    } else if (m > 0 && n > 0) {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

int main() {
    int m, n;
    printf("Ingrese el valor de m: ");
    scanf("%d", &m);
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);

    int resultado = ackermann(m, n);
    printf("A(%d, %d) = %d\n", m, n, resultado);

    return 0;
}

