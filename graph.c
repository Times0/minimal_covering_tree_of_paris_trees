#include <stdlib.h>
#include <stdio.h>
#include "pair.h"

typedef  struct {
    int *noeuds;
    pair_t **coords;
    int **adjacences;
}graph;


graph* create_graph(){
    graph *g = malloc(sizeof(graph));
    return g;
}

void free_graph(graph *g){
    free(g->coords);
    free(g->noeuds);
    free(g);
}
