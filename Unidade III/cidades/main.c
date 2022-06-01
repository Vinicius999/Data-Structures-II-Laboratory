#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define N 9152

void rotas(double *graph);
double maxPercurso(double *graph);
double minPercurso(double *graph);
double medPercurso(double *graph);
double distance(double latit_i, double longit_i, double latit_j, double longit_j);


int main() {
    FILE *file = fopen("ar9152.tsp", "r");
    int c;
    float la;
    float lg;
    double cid_la[N];
    double cid_lg[N];

    /*Inicializa graph*/
    double *graph;
    graph = (double*) malloc(N*N*sizeof(double));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            graph[i*N + j] = 0.;
        }
    }
    

    int k = 0;
    while (!feof(file)){
        fscanf(file, "%d %f %f", &c, &la, &lg);
        cid_la[k] = la;
        cid_lg[k] = lg;
        k++;
    }
    fclose(file);
    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            //graph[i*N + j] = sqrt(pow(cid_la[i] - cid_la[j], 2) + pow(cid_lg[i] - cid_lg[j], 2));
            graph[i*N + j] = distance(cid_la[i],cid_lg[i],cid_la[j],cid_lg[j]);
        }
    }
    
    printf("\n Maior distancia entre duas cidades:\n > %f\n", maxPercurso(graph));
    printf("\n Menor distancia entre duas cidades:\n > %f\n", minPercurso(graph));
    printf("\n Distancia média entre duas cidades:\n > %f\n", medPercurso(graph));
    
    rotas(graph);
}


void rotas(double *graph) {
    FILE *f = fopen("tourar9152.tour", "r");
    int a, b, count=1;
    double sum = 0.0;
    fscanf(f, "%d", &a);
    fscanf(f, "%d", &b);
    if(a > b){
        sum = sum + graph[b*N+a];
    }else{
        sum = sum + graph[a*N+b];
    }
    while (!feof(f)) {
        //printf("Rotas %d %d\n", a, b);
        a = b;
        fscanf(f, "%d", &b);

        if(a>b){
            sum = sum + graph[b*N + a];
        }else{
            sum = sum + graph[a*N + b];
        }

        if(sum <= 68638254.213346*0.8){
            count++;
        }
    }

    printf("\n Distância total:\n > %f\n", sum);
    printf("\n Cidades visitadas para percorrer 80%% do tour:\n > %d\n\n", count);

    fclose(f);
}

double maxPercurso(double *graph) {
    double maior = 0.0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(graph[i*N + j] > maior){
                maior = graph[i*N + j];
            }
        }
    }
    return maior;
}

double minPercurso(double *graph) {
    double menor = graph[0*N + 1];
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(graph[i*N + j]<menor && graph[i*N + j] != 0.0){
                menor = graph[i*N + j];
            }
        }
    }
    return menor;
}

double medPercurso(double *graph) {
    int count = 0;
    double sum = 0.0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(graph[i*N + j] != 0.0){
                count++;
                sum = sum + graph[i*N + j];
            }
        }
    }
    return (sum / ((N*(N-1)) / 2));
}

double distance(double latit_i, double longit_i,double latit_j, double long_j) {
    double dist = sqrt(pow(latit_i - latit_j, 2) + pow(longit_i - long_j, 2));
    return dist;
}
