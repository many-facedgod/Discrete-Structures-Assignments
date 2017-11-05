#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int relation[MAX][MAX];
int n_elems;

void read()
{
    scanf("%d", &n_elems);
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        relation[x][y] = 1;
    }

}

void generate()
{
    int i, j, k;
    for(i = 0; i < n_elems; i++)
    {
        for(j = 0; j < n_elems; j++)
        {
            for(k = 0; k < n_elems; k++)
            {
                if(relation[j][i] && relation[i][k])
                    relation[j][k] = 1;
            }
        }
    }

}

void print()
{
    int i, j, c;
    for(i = 0; i < n_elems; i++)
    {
        c = 0;
        for(j = 0; j < n_elems; j++)
        {
            if(relation[i][j] == 1 && j!=i)
            {
                c++;
                printf("%d ", j);
            }
        }
        if(c == 0)
            printf("-");
        printf("\n");
    }
}

int main()
{
    read();
    generate();
    print();
}
