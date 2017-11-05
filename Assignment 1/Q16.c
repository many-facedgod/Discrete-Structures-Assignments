#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int relation[MAX][MAX];
int count[MAX];
int n;

void read()
{
    scanf("%d", &n);
    int i, k;
    scanf("%d", &k);
    for(i = 0; i < k; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        relation[x][y] = 1;
        count[y]++;
    }
}

int check()
{
    int i, j, flag = 1;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(count[j] == 0)
            {
                count[j]--;
                int k;
                for(k = 0; k < n; k++)
                    if(relation[j][k] == 1)
                        count[k]--;
                break;
            }
        }
        flag = j != n;
    }
    return flag;
}

void solve()
{
    if(check())
        printf("Possible\n");
    else
        printf("Not Possible\n");
}

int main()
{
    read();
    solve();
}
