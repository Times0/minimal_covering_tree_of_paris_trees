#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

/*Graphe classique*/
graph *create_graph(int n)
{
    graph *g = malloc(sizeof(graph));
    g->size = n;
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
    for (size_t i = 0; i < g->size; i++)
    {
        free(g->adjacences[i]);
    }

    free(g->adjacences);
    for (size_t i = 0; i < g->size; i++)
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
    graph_complet *g = malloc(sizeof(graph));
    g->size = n;
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
    for (size_t i = 0; i < g->size; i++)
    {
        coord_free(g->coords[i]);
    }
    free(g->coords);
    free(g->noeuds);
    free(g);
}

graph *acm_complet(graph_complet *g)
{
    int n = g->size;
    graph *minct = create_graph(n);
    for (size_t i = 0; i < n; i++)
    {
        minct->coords[i] = g->coords[i];
    }

    int to_see[n];
    int *seen = calloc(n, sizeof(int));
    seen[0] = 1;

    return minct;
}

#define INF 9999999

graph *acm_complet_prim(graph_complet *g)
{
    int n = g->size;
    graph *res = create_graph(n);
    for (size_t i = 0; i < n; i++)
    {
        res->coords[i] = g->coords[i];
    }
    int no_edge; // number of edge

    // create a array to track selected vertex
    // selected will become true otherwise false
    int selected[n];

    // set selected false initially
    memset(selected, false, sizeof(selected));

    // set number of edge to 0
    no_edge = 0;

    // the number of egde in minimum spanning tree will be
    // always less than (V -1), where V is number of vertices in
    // graph

    // choose 0th vertex and make it true
    selected[0] = true;

    int x; //  row number
    int y; //  col number

    while (no_edge < n - 1)
    {
        // For every vertex in the set S, find the all adjacent vertices
        //  , calculate the distance from the vertex selected at step 1.
        //  if the vertex is already in the set S, discard it otherwise
        // choose another vertex nearest to selected vertex  at step 1.
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!selected[j])
                    { // not in selected and there is an edge
                        double dist = distance(g->coords, i, j);
                        if (min > dist)
                        {
                            min = dist;
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        res->adjacences[x][y] = distance(g->coords, x, y);
        selected[y] = true;
        no_edge++;
    }

    return res;
}