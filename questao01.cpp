#include <stdio.h>
#include <time.h>

// Questão 01 - Programa para Calcule o tempo (em segundos) necessário para rodar esse algoritmo:

//Algoritmo a ser calculado o tempo de execucao
int algoritmoDemorado (int n) {
	int soma = 0;
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < n; l++) {
					soma = (i + j + k + l);
				}
			}
		}
	}
	return soma;
}

// programa principal
int main (){
	int n;    
	printf("Digite um valor inteiro para ser calculado: "); //Aqui definimos o tamanho de n
    scanf("%d", &n);

	float tempo;
	time_t t_ini, t_fim;    //criamos as variaveis tempo inicial e tempo final
	
	t_ini = time(NULL);     //iniciamos o t_inicial com um valor NULL
	t_fim = algoritmoDemorado(n);
	t_fim = time(NULL);     //atribuimos o ao t_final o valor NULL apos a execucao da funcao
	
	tempo = difftime(t_fim, t_ini);     // calculamos a diferença entre o tempo final e o tempo inicial
	
    printf("\n\t|=====================================|\n");
	printf("\t|Tempo de execucao = %.2f Segundos    |\n", tempo);  /* exibimos na tela o valor em segundos do 
                                                               tempo de execucao armazenado na variavel tempo */
    printf("\t|=====================================|\n");

	return 0;
}