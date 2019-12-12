#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
}; 

int main()
{
    Grafo *gr = init_grafo(10, 7, 0);
    return 0;
}

Grafo* init_grafo(int nro_vertices, int grau_max, int eh_ponderado)
{
    Grafo* gr = (Grafo*) malloc(sizeof(Grafo));
    if(gr != NULL){
        int i, j;

        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0) ? 1 : 0;

        gr->grau = (int*)calloc(nro_vertices, sizeof(int));
        gr->arestas = (int**) malloc(nro_vertices*sizeof(int*));


        for(i = 0; i < nro_vertices; i++){
            
            gr->arestas[i] = (int*)malloc(grau_max*sizeof(int));
            
            if(gr->eh_ponderado){
                
                gr->pesos = (float**)malloc(nro_vertices * sizeof(float*));
                
                for(j = 0; j < nro_vertices; j++) 
                    gr->pesos[i] = (float*) malloc(grau_max * sizeof(float));
            }
        }
    }

    return gr;
}

void free_grafo(Grafo* gr)
{
    if(gr != NULL){
        int i;
        for(i = 0; i < gr->nro_vertices; i++){
            free(gr->arestas[i]);
        }
        free(gr->arestas);

        if(gr->eh_ponderado){
            for(i = 0; i < gr->nro_vertices; i++){
                free(gr->pesos[i]);
            }

            free(gr->pesos);
        }
        free(gr->grau);
    }
    free(gr);
}