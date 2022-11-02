#include "coords.h"
#include "graph.h"
#include <stdio.h>
#include "tps_unit_test.h"

TEST_INIT_GLOBAL


void test_coords(){
    coord_t *c = coord_create(500,600);
    tps_assert(c!=NULL);
    tps_assert(c->x == 500);
    coord_free(c);
}

void test_graph(){
  graph *g = create_graph(5);
  tps_assert(g!=NULL);

  for (size_t i = 0; i < 5; i++)
  {
    g->noeuds[i] = i;
  }
  tps_assert(g->noeuds[4] == 4);

  for (size_t i = 0; i < 5; i++)
  {
    g->coords[i] = coord_create(500,600);
  }
  tps_assert(g->coords[1]->x == 500);
  free_graph(g);
  
}


int main(void)
{
  TEST(test_coords);
  TEST(test_graph);
}
