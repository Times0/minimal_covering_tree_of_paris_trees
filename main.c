#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "coords.h"
#include "graph.h"

char *trunca(const char *s, int a, int b)
{
    int n = b - a + 1;
    char *res = malloc((n + 1) * sizeof(char));
    for (int i = 0; i < b - a - 1; i++)
    {
        res[i] = s[a + i];
    }
    res[b - a] = '\0';

    return res;
}

const char *getfield(const char *line, int num)
{
    int a = -1;
    int b = -1;

    if (num == 0)
    {
        a = 0;
        for (int i = 0; line[i] != '\0'; i++)
        {
            if (line[i] == ';')
            {
                b = i;
                break;
            }
        }
    }
    else
    {
        int nb_occurence_comma = 0;
        for (int i = 0; line[i] != '\0'; i++)
        {
            if (line[i] == ';')
            {
                nb_occurence_comma++;
                if (nb_occurence_comma == num)
                {
                    a = i;
                }
                else if (nb_occurence_comma == num + 1)
                {
                    b = i;
                    break;
                }
            }
            if (line[i + 1] == '\0')
            {
                b = i;
                break;
            }
        }
    }

    if (a == -1 || b == -1)
    {
        return NULL;
    }
    // printf("a:%d b:%d\n",a,b);
    char *res = trunca(line, a + 1, b + 1);
    return res;
}

int main(int argc, char **argv)
{
    int flag_i = 0;
    char *value_i = NULL;

    int flag_s = 0;
    int option;

    while ((option = getopt(argc, argv, ":si:")) != -1)
    {
        switch (option)
        {
        case 's':
            flag_s = 1;
            break;
        case 'i':
            flag_i = 1;
            value_i = optarg;
            break;
        case ':':
            printf("option needs a value");
            exit(1);
            break;
        case '?':
            printf("unknown option: %c\n", optopt);
            break;
        }
    }

    if (!flag_i)
    {
        printf("-i is mandatory\n");
        exit(1);
    }

    FILE *csvfile = fopen(value_i, "r");
    char line[1024];


    int n = 10000;
    printf("n : %d\n", n);
    graph_complet *g = create_graph_complet(n);
    printf("Initialised graph\n");
    fgets(line, 1024, csvfile); // get rid of the first line with name of columns
    int c = 0;
    while (fgets(line, 1024, csvfile) && c < n)
    {
        double a,b;
        sscanf(getfield(line, 16), "%lf,%lf", &a, &b);
        g->coords[c] = coord_create(a, b);
        g->noeuds[c] = c;
        c++;
    }
    printf("Done parsing csv and creating graph\n");

    int num = n / 2;
    printf("Node nb %d, coords : ", g->noeuds[num]);
    printcoord(g->coords[num]);
    
    graph *acm = acm_complet_prim(g);

    printf("Created minimal spanning tree\n");

    free_graph_complet(g);
    return 0;
}
