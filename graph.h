#if !defined(GRAPH_H)
#define GRAPH_H
#include "coords.h"
#include <stdbool.h>
#include <string.h>

typedef struct graph
{
    int size;
    int *noeuds;
    coord_t **coords;
    double **adjacences;
} graph;

graph *create_graph(int n);

void free_graph(graph *g);

typedef struct graph_complet
{
    int size;
    int *noeuds;
    coord_t **coords;
} graph_complet;

graph_complet *create_graph_complet(int n);

graph *acm_complet(graph_complet *g);

graph *acm_complet_prim(graph_complet *g);

void free_graph_complet(graph_complet *g);

#endif // GRAPH_H
