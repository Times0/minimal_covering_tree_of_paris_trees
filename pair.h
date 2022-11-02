#ifndef PAIR_H
#define PAIR_H

typedef struct pair_t
{
  double x;
  double y;
} pair_t;

/**
  create a pair of elements
*/
pair_t *pair_create(double first, double second);

/**
  get the first element of the pair
*/
double pair_get_first(pair_t *pair);

/**
  get the first element of the pair
*/
double pair_get_second(pair_t *pair);

/**
  free the pair but not the element
*/
void pair_free(pair_t *pair);

/**
  swap the first and the second elements
*/
void pair_swap(pair_t *pair);


void printpair(pair_t *pair);

#endif