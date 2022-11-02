#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "pair.c"
#include <math.h>
#include "graph.c"

char* trunca(const char * s, int a, int b){
    int n = b-a+1;
    char *res = malloc((n+1)*sizeof(char));
    for (int i = 0; i < b-a-1; i++)
    {
        res[i] = s[a+i];
    }
    res[b-a]='\0';
    
    return res;
}

const char* getfield(const char* line, int num)
{
    int a = -1;
    int b = -1;
    
    if (num==0)
    {
        a=0;
        for (int i = 0; line[i] != '\0'; i++)
        {
            if (line[i]==';'){b=i;break;}
        }
    }
    else{
        int nb_occurence_comma = 0;
        for (int i = 0; line[i] != '\0'; i++)
        {
            if (line[i] == ';'){
                nb_occurence_comma ++;
                if (nb_occurence_comma == num){a = i;}
                else if (nb_occurence_comma == num+1){b = i;break;}                
            }
            if (line[i+1]=='\0'){b=i;break;}
        }
    }
    
    if (a==-1 || b==-1){return NULL;}
    //printf("a:%d b:%d\n",a,b);
    char* res= trunca(line, a+1 ,b+1);
    return res;
}

double _distance(pair_t *a, pair_t *b){
    return sqrt((a->x - b->x)*(a->x - b->x) + (a->y-b->y)*((a->y-b->y)));
}

double distance(pair_t **coords, int i, int j){
    return _distance(coords[i], coords[j]);
}

int 
main(int argc, char** argv){
    int flag_i = 0;
    char *value_i = NULL;

    int flag_s = 0;
    int option;

    

    while((option = getopt(argc, argv, ":si:")) != -1){
        switch(option){
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

    if (!flag_i){printf("-i is mandatory\n");exit(1);}
    
    FILE *csvfile = fopen(value_i, "r");
    char line[1024];

    int c = 0;

    int n = 200000;
    graph *g = create_graph();
    pair_t **l_noeuds = malloc(sizeof(pair_t) * n);
    g->noeuds = malloc(sizeof(int) * n);
    fgets(line,1024,csvfile); //get rid of the first line with name of columns
    while (fgets(line, 1024, csvfile)&&c<n)
    {
        double a;
        double b;
        sscanf(getfield(line, 16),"%lf,%lf", &a, &b);
        pair_t *coords = pair_create(a,b);
        l_noeuds[c] = coords;
        //printf("Adresse de l'arbre %d : c1 is %lf c2 is %lf\n",atoi(getfield(line,0)),pair_get_first(coords),pair_get_second(coords));
        g->noeuds[c] = c;
        c++;
    }

    g->coords = l_noeuds;
    
    printf("Noeud numéro %d, coords : ", g->noeuds[75]);
    printpair(g->coords[75]);
    free_graph(g);
    return 0;
}