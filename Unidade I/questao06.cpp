#include <stdio.h>
#include <stdlib.h>


void invert(int v[], int ini, int end){
    int aux;

    if(ini < end){
        aux = v[ini];
        v[ini] = v[end];
        v[end] = aux;
        invert(v, ini + 1, end - 1);
    }
}

void show(int v[], int lengh){
    if(lengh == 1)
        printf("%d ", v[lengh - 1]);
    else{
        show(v, lengh - 1);
        printf("%d ", v[lengh - 1]);
    }
}


int main() {

    int n; // Tamanho do vetor

    printf("-----------------------------------------\n");
    printf("\t INVERSOR DE VETOR\n");
    printf("-----------------------------------------\n");

    printf("Quantos elementos tem o vetor?\n>> ");
    scanf("%d", &n);
    int vet[n];

    printf("\nInsira os elementos:\n");
    int i;
    for (i = 0; i < n; i++) {  // Inserindo elementos no vetor
        printf("%dº: ", i+1);
        scanf("%d", &vet[i]);
    }

    printf("\nVetor original: \n");
    show(vet, n); // Printando vetor original 

    invert(vet, 0, n-1); 
    printf("\n\nVetor invertido: \n");
    show(vet, n);  // Printando vetor invertido
    printf("\n\n");

    return 0;
}