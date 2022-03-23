#include <stdio.h>
#include <string.h>


int funPalindromo(char *n, int tam, int pos);
int palindromo(char *n);


int main() {
    int i = 0, pos;
    char frase[100];

    printf("Digite uma frase: ");
    scanf ("%[^\n]", frase);
    
    int tama = strlen(frase);

    for (i = 0, pos = 0; i < tama; i++, pos++){
        if (frase[pos] == ' '){
            pos++;
        }
        frase[i] = frase[pos];
    }
    
    printf("String sem espacos: %s\n\n", frase);

    palindromo(frase);

    return 0;
}

int funPalindromo(char *n, int tam, int pos){

    if (pos < tam / 2){
        if (n[pos] == n[tam - pos - 1])
            return funPalindromo(n, tam, pos+1);
        
        else
            return 0; 
    }
    else
        return 1;
}


int palindromo(char *n) { 

    int aux1, x = 0;

    aux1 = funPalindromo(n, strlen(n), x);

    if (aux1 == 1) {
        printf("E um palindromo\n\n");
    }
    else {
        printf("Nao e palindromo\n\n");
    }
}