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


typedef struct graph_complet
{
    int n;
    int *noeuds;
    coord_t **coords;
} graph_complet;

graph_complet* create_graph_complet(int n);

void free_graph_complet(graph_complet *g);

double djikstra(graph_complet *g);

#endif // GRAPH_H

