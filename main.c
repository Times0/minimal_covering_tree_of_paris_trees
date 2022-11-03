#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "coords.h"
#include "graph.h"

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
    printf("n : %d\n",n);
    graph *g = create_graph(n);
    printf("Created graph\n");
    g->coords[0] = coord_create(500,266);
    fgets(line,1024,csvfile); //get rid of the first line with name of columns
    while (fgets(line, 1024, csvfile)&&c<n)
    {
        double a;
        double b;
        sscanf(getfield(line, 16),"%lf,%lf", &a, &b);
        coord_t *coords = coord_create(a,b);
        g->coords[c] = coords;
        //printf("Adresse de l'arbre %d : c1 is %lf c2 is %lf\n",atoi(getfield(line,0)),coord_get_first(coords),coord_get_second(coords));
        g->noeuds[c] = c;
        c++;
    }
    printf("Done parsing csv\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i==j){continue;}
            g->adjacences[i][j] = distance(g->coords, i, j);
        }
    }
    

    int num = n /2;
    printf("Node nb %d, coords : \n", g->noeuds[num]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j){continue;}
            printf("Distance %d -> %d : %lf\n", i,j, g->adjacences[i][j]);
        }
        
    }
    
    printcoord(g->coords[num]);
    free_graph(g);
    return 0;
}