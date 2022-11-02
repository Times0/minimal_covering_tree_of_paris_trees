#if !defined(GRAPH_H)
#define GRAPH_H
#include "coords.h"


typedef struct graph
{
    int n;
    int *noeuds;
    coord_t **coords;
    double **adjacences;
} graph;


graph* create_graph(int n);

void free_graph(graph *g);




#endif // GRAPH_H

