#include "coords.h"
#include "graph.h"
#include <stdio.h>
#include "tps_unit_test.h"

TEST_INIT_GLOBAL

void test_coords()
{
  coord_t *c = coord_create(500, 600);
  tps_assert(c != NULL);
  tps_assert(c->x == 500);
  coord_free(c);
}

void test_graph_complet()
{
  int n = 10;
  graph_complet *g = create_graph_complet(n);
  for (int i = 0; i < n; i++)
  {
    tps_assert(g->noeuds[i] == i);
  }
  free_graph_complet(g);
}

void test_graph()
{
  int n = 5;
  graph *g = create_graph(n);
  tps_assert(g != NULL);

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
    g->coords[i] = coord_create(500, 600);
    tps_assert(g->noeuds[i] == i);
    tps_assert(g->coords[i]->x == 500);
  }
  free_graph(g);
}

/*
void test_priority_q(){
  double array[10];
  insert(array, 3);
  insert(array, 4);
  insert(array, 9);
  insert(array, 5);
  insert(array, 2);
  tps_assert(array[0] == 9);

}*/

void test_acm()
{
  graph_complet *g = create_graph_complet(3);
  g->coords[0] = coord_create(347, 370);
  g->coords[1] = coord_create(646, 187);
  g->coords[2] = coord_create(855, 574);

  graph *acm = acm_complet(g);
  tps_assert(acm != NULL);
  tps_assert(acm->size == g->size);
  tps_assert(acm->coords != g->coords);
  tps_assert(acm->coords[0] == g->coords[0]);
  tps_assert(acm->adjacences[0][1] != 0);
  tps_assert(acm->adjacences[1][2] != 0);
  tps_assert(acm->adjacences[0][0] == 0);
  tps_assert(acm->adjacences[0][2] == 0);
}

void test_prims()
{
  graph_complet *g = create_graph_complet(3);
  g->coords[0] = coord_create(347, 370);
  g->coords[1] = coord_create(646, 187);
  g->coords[2] = coord_create(855, 574);
  graph *acm = acm_complet_prim(g);

  tps_assert(acm != NULL);
  tps_assert(acm->size == g->size);
  tps_assert(acm->coords != g->coords);
  tps_assert(acm->coords[0] == g->coords[0]);
  tps_assert(acm->adjacences[0][1] != 0);
  tps_assert(acm->adjacences[1][2] != 0);
  tps_assert(acm->adjacences[0][0] == 0);
  tps_assert(acm->adjacences[0][2] == 0);

  free_graph(acm);
  free_graph(g);
}

int main(void)
{
  TEST(test_coords);
  TEST(test_graph_complet);
  TEST(test_graph);
  TEST(test_prims);
}
