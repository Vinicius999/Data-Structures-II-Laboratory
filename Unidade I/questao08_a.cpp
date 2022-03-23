#include <stdio.h>
#include <stdlib.h>



int factorial(int n) {
    int nn;
    if (n == 0 || n == 1) { // Caso base
        printf("%d ", 1);
        return 1;
    }
    else {
        nn = n * factorial(n - 1);
        printf("x %d ", n);
        return (nn);
    }
} 

int main() {
    int n;   // Valor a ser calculado o fatorial

    printf("-----------------------------------------\n");
    printf("\t\t FATORIAL\n");
    printf("-----------------------------------------\n");

    printf("Insira o valor: ");
    scanf("%d", &n);

    printf("\nResultado: %d! = ", n);
    int fat = factorial(n);
    printf(" = %d\n", fat);

    return 0;
}