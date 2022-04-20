#ifndef ALUNO_C
#define ALUNO_C
#include<stdlib.h>

typedef struct aluno{
    int id;
    char *nome;
    float nota;
}*Aluno;

Aluno criarAluno(int a, char* b, float c){
    Aluno A =(Aluno) malloc(sizeof(struct aluno));
    A->id = a;
    A->nome = b;
    A->nota = c;
    return A;
}

void modificarNota(Aluno A, float novaNota){
    A->nota = novaNota;
}

char* toStringAluno(Aluno A){
    return A->nome;
}
#endif
