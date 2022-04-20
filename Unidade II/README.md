# Árvore BinaryTree

## Arquivos iniciais

### Arquivo aluno.c

```cpp
#include<stdlib.h>
typedef struct aluno{
    int id;
    char *nome;
    float nota;
}*Aluno;

Aluno criarAluno(int a, char* b, unsigned short c){
    Aluno A =(Aluno) malloc(sizeof(struct aluno));
    A->id = a;
    A->nome = b;
    A->nota = c;
    return A;
}

void modificarNota(Aluno A, float novaNota){
    A->nota = novaNota;
}
```

### binaryTree.c

```cpp
#include<stdio.h>
#include<stdlib.h>
#include "aluno.c"

typedef struct node {
    Aluno A;
    struct node* esq;
    struct node* dir;
}*No;

typedef No noRaiz;

noRaiz criarArvore();
int inserir(noRaiz, Aluno);
int inserirEmLote(noRaiz, noRaiz);
int remover(noRaiz, Aluno a);
Aluno buscar(noRaiz, Aluno a);
void deletarArvore(noRaiz);

//Recursivo
void preordemRec(noRaiz);
void inordemRec(noRaiz);
void posordemRec(noRaiz);
void nivelRec(noRaiz);

//Iterativo
void preordemIter(noRaiz);
void inordemIter(noRaiz);
void posordemIter(noRaiz);
void nivelIter(noRaiz);

int altura(noRaiz);
int alturaDoNo(noRaiz);
void valoresEntre(int idA, int idB);

int tempoDeBusca();
int tempoDeRemocao();
int tempoDeInsercao();


int main( )
{
    Aluno K = criarAluno(10, "Kennedy Lopes\0", 9.);
    No raiz = malloc(sizeof(struct node));
    raiz->esq = 0;
    raiz->dir = 0;
    raiz->A = K;
}
```

## Documentação

Reintepretação do No para NoRaiz (Não há nada a ser feito aqui)
> typedef No noRaiz;

---

Criando uma árvore e retornando o noRaiz
> noRaiz criarArvore();

---

Inserindo um **Aluno a** na árvore a partir do nó raiz;
> int inserir(noRaiz, Aluno a);

---

Inserindo um conjunto de Alunos em uma única chamada.
> int inserirEmLote(noRaiz, Aluno*, int);

---

Removendo um aluno de uma árvore a partir do noRaiz;
> int remover(noRaiz, Aluno a);

---

Buscando um aluno. Caso exista, retornar uma referência para sua localização na árvore
> Aluno buscar(noRaiz, Aluno a);

---

Eliminando a árvore por completo. O ideal é utilizar o método *free*(biblioteca stdlib)  para todos os elementos da árvore

> void deletarArvore(noRaiz);

---


Versão Recursiva dos percursos em árvores (os valores devem imprimir os nomes dos Alunos)
> void preordemRec(noRaiz);

> void inordemRec(noRaiz);

> void posordemRec(noRaiz);

---

Versão iterativo dos percursos em árvores (os valores devem imprimir os nomes dos Alunos)

> void preordemIter(noRaiz);

> void inordemIter(noRaiz);

> void posordemIter(noRaiz);

---

Cálculo da altura de uma árvore a partir do nó raiz
> int altura(noRaiz);

---

Cálculo dos valores entre idA e idB (índices cadastrados do alunos)
> void valoresEntre(noRaiz n, int idA, int idB);

Realiza as mesmas operações de busca, remoção e inserção mas retorna (em forma de impressão na tela) o tempo para realizar essas operações
> int tempoDeBusca(noRaiz, Aluno a);
> int tempoDeRemocao(noRaiz, Aluno a);
> int tempoDeInsercao(noRaiz, Aluno a);
