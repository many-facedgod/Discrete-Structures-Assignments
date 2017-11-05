#include <stdio.h>
#include <stdio.h>
#define MAX 1000
int relation[MAX][MAX];
int num;

void read()
{
    scanf("%d", &num);
    int k, i;
    scanf("%d", &k);
    for(i = 0; i < k; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        relation[x][y] = 1;
    }
}

int is_reflexive()
{
    int i;
    for(i = 0; i < num; i++)
    {
        if(relation[i][i] == 0)
            return 0;
    }
    return 1;
}

int is_antisymm()
{
    int i, j;
    for(i = 0; i < num; i++)
    {
        for(j = 0; j < num; j++)
        {
            if(relation[i][j] == 1 && relation[j][i] == 1 && i != j)
                return 0;
        }
    }
    return 1;
}

int is_transitive()
{
    int i, j, k;
    for(i = 0; i < num; i++)
    {
        for(j = 0; j < num; j++)
        {
            for(k = 0; k < num; k++)
            {
                if(relation[i][j] == 1 && relation[j][k] == 1 && relation[i][k] == 0)
                    return 0;
            }
        }
    }
    return 1;
}

void solve()
{
    int r = is_reflexive();
    int as = is_antisymm();
    int tr = is_transitive();
    if(r && as && tr)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}

int main()
{
    read();
    solve();
}
