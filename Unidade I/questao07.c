#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float raiz(int x, float x0, float e){

    if ( ((x0 * x0) - x) * (-1) <= e){
        return x0;
    }
    else {
        return raiz(x, ((x0 * x0) + x) / (2 * x0), e);
    }
}

int main(void){
    int x;
    float x0, e, valor;

    printf("\n\nDIGITE TRES VALORES (X, X0, E): \n");
    printf("X: ");
    scanf("%d", &x);
    printf("X0: ");
    scanf("%f", &x0);
    printf("X0: ");
    scanf("%f", &e);

    valor = raiz(x, x0, e);
    printf("\nRESULTADO: %f\n\n", valor);

    return 0;
}