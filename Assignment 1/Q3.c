#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int dep_graph[MAX][MAX];
int depends_on[MAX];
int n_nodes;

void read()
{
    scanf("%d", &n_nodes);
    int n;
    scanf("%d", &n);
    int i;
    for(i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        dep_graph[x][y] = 1;
        depends_on[y]++;
    }
}

void toposort()
{
    int i, j, k;
    for(i = 0; i < n_nodes; i++)
    {
        for(j = 0; j < n_nodes; j++)
        {
            if(depends_on[j] == 0)
            {
                printf("%d ", j);
                depends_on[j]--;
                for(k = 0; k < n_nodes; k++)
                    if(dep_graph[j][k] == 1)
                        depends_on[k]--;
                break;
            }
        }
    }

}

int main()
{
    read();
    toposort();
}
