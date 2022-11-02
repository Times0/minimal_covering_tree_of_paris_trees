#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

graph* create_graph(int n){
    graph *g = malloc(sizeof(graph));
    g->adjacences = (double **)malloc(n * sizeof(double*));
    for(int i = 0; i < n; i++) g->adjacences[i] = (double *)malloc(n * sizeof(int));
    g->noeuds = malloc(sizeof(int) * n);
    g->coords = malloc(sizeof(coord_t) * n); 
    return g;
}

void free_graph(graph *g){
    free(g->adjacences);
    for (size_t i = 0; i < g->n; i++)
    {
        coord_free(g->coords[i]);
    }
    
    free(g->coords);
    free(g->noeuds);
    free(g);
}