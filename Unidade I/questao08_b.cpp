#include <stdio.h>
#include <stdlib.h>


int factorial_aux(int n, int acc) {
    if (n == 0 || n == 1)
        return acc;
    else
        printf("%d x ", n);
        return factorial_aux((n - 1), (acc * n));
}

int factorial_tail(int n) {
    return factorial_aux(n, 1);
}


int main() {
    int n;   // Valor a ser calculado o fatorial

    printf("-----------------------------------------\n");
    printf("\t\t FATORIAL\n");
    printf("-----------------------------------------\n");

    printf("Insira o valor: ");
    scanf("%d", &n);

    printf("\nResultado: %d! = ", n);
    int fat = factorial_tail(n);
    printf("1 = %d\n", fat);

    return 0;
}