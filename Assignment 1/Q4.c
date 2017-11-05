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

int count_toposort()
{
    int i, count = 0;
    int flag = 0;
    for(i = 0; i < n_nodes; i++)
    {
        if(depends_on[i] == 0)
        {

            flag++;
            depends_on[i]--;
            int j;
            for(j = 0; j < n_nodes; j++)
                if(dep_graph[i][j] == 1)
                    depends_on[j]--;
            count += count_toposort();
            depends_on[i]++;
            for(j = 0; j < n_nodes; j++)
                if(dep_graph[i][j] == 1)
                    depends_on[j]++;

        }
    }
    if(flag == 0)
        return 1;
    return count;

}

int main()
{
    read();
    printf("%d\n", count_toposort());
}
