#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/*Graphe classique*/
graph *create_graph(int n)
{
    graph *g = malloc(sizeof(graph));
    g->n = n;
    g->adjacences = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
        g->adjacences[i] = (double *)calloc(n, sizeof(double));
    g->noeuds = malloc(sizeof(int) * n);
    for (size_t i = 0; i < n; i++)
    {
        g->noeuds[i] = i;
    } // init nodes values
    g->coords = malloc(sizeof(coord_t) * n);
    return g;
}

void free_graph(graph *g)
{
    for (size_t i = 0; i < g->n; i++)
    {
        free(g->adjacences[i]);
    }

    free(g->adjacences);
    for (size_t i = 0; i < g->n; i++)
    {
        coord_free(g->coords[i]);
    }
    free(g->coords);
    free(g->noeuds);
    free(g);
}

/*Graphe dense / graphe complet*/
graph_complet *create_graph_complet(int n)
{
    graph *g = malloc(sizeof(graph));
    g->n = n;
    g->noeuds = malloc(sizeof(int) * n);
    for (size_t i = 0; i < n; i++)
    {
        g->noeuds[i] = i;
    } // init nodes values
    g->coords = malloc(sizeof(coord_t) * n);
    return g;
}

void free_graph_complet(graph_complet *g)
{
    for (size_t i = 0; i < g->n; i++)
    {
        coord_free(g->coords[i]);
    }
    free(g->coords);
    free(g->noeuds);
    free(g);
}

double djikstra(graph_complet *g)
{
    return 0.0;
}
