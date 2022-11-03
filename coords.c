#include <stdio.h>
#include <stdlib.h>
#include "coords.h"
#include <math.h>

coord_t *coord_create(double x, double y)
{
    coord_t *elem = malloc(sizeof(*elem));
    if (!elem)
    {
        return NULL;
    }
    elem->x = x;
    elem->y = y;
    return elem;
}

double coord_get_first(coord_t *coord)
{
    return coord->x;
}

double coord_get_second(coord_t *coord)
{
    return coord->y;
}

void coord_free(coord_t *coord)
{
    free(coord);
}

void coord_swap(coord_t *coord)
{
    double temp = coord->x;
    coord->x = coord->y;
    coord->y = temp;
}

void printcoord(coord_t *coord)
{
    printf("%lf, %lf\n", coord_get_first(coord), coord_get_second(coord));
}

double _distance(coord_t *a, coord_t *b)
{
    return sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * ((a->y - b->y)));
}

double distance(coord_t **coords, int i, int j)
{
    return _distance(coords[i], coords[j]);
}
