#include <stdio.h>
#include <stdlib.h>
#include "pair.h"

pair_t *pair_create(double x, double y){
    pair_t *elem = malloc(sizeof(*elem));
    if (!elem){
        return NULL;
    }
    elem->x=x;
    elem->y = y;
    return elem;
}

double pair_get_first(pair_t *pair){
    return pair->x;
}

double pair_get_second(pair_t *pair){
    return pair->y;
}

void pair_free(pair_t *pair){
    free(pair);
}

void pair_swap(pair_t *pair){
    double temp = pair->x;
    pair->x = pair->y;
    pair->y = temp;
}

void printpair(pair_t *pair){
    printf("%lf, %lf\n", pair_get_first(pair),pair_get_second(pair));
}

