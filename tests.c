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

void test_graph_complet(){
  int n = 10;
  graph_complet *g = create_graph_complet(n);
  for (int i = 0; i < n; i++)
  {
    tps_assert(g->noeuds[i] == i);
  }
  free_graph_complet(g);
}

void test_graph(){
  int n = 5;
  graph *g = create_graph(n);
  tps_assert(g!=NULL);

  // test calloc init

  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      tps_assert(g->adjacences[i][j] == 0);
    }
    
  }
  

  for (size_t i = 0; i < 5; i++)
  {
    g->coords[i] = coord_create(500,600);
    tps_assert(g->noeuds[i] == i);
    tps_assert(g->coords[i]->x == 500);  
  }
  free_graph(g);
}

int main(void)
{
  TEST(test_coords);
  TEST(test_graph_complet);
  TEST(test_graph);
}
