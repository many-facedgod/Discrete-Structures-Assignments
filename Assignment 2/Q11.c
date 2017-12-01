#include <stdio.h>
#include <stdlib.h>
#define MAX 30
int n;
int admat[MAX][MAX];
int marked[MAX];
int count = 0;
void read(int directed)
{
    scanf("%d", &n);
    int x;
    scanf("%d", &x);
    int i;
    for(i = 0; i < x; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        admat[a][b] = 1;
        if(!directed)
            admat[b][a] = 1;
    }
}

void dfs(int i)
{
        if(marked[i])
                return;
        else
        {
                marked[i] = 1;
                int j;
                for(j = 0; j < n; j++)
                {
                        if(admat[i][j] == 1)
                                dfs(j);
                }
        }
}

void solve()
{
        int i;
        for(i = 0; i < n; i++)
        {
                if(!marked[i])
                {
                        dfs(i);
                        count++;
                }
        }
}

int main()
{
        read(0);
        solve();
        printf("%d\n", count - 1);
}
