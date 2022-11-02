#if !defined(COORDS_H)
#define COORDS_H


typedef struct coord_t
{
  double x;
  double y;
} coord_t;

/**
  create a coord of elements
*/
coord_t *coord_create(double first, double second);

/**
  get the first element of the coord
*/
double coord_get_first(coord_t *coord);

/**
  get the first element of the coord
*/
double coord_get_second(coord_t *coord);

/**
  free the coord but not the element
*/
void coord_free(coord_t *coord);

/**
  swap the first and the second elements
*/
void coord_swap(coord_t *coord);


void printcoord(coord_t *coord);


double _distance(coord_t *a, coord_t *b);


double distance(coord_t **coords, int i, int j);

#endif // COORDS_H
