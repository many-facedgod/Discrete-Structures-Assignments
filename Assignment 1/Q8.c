#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int n;
int skips[MAX];
int mark[MAX];
int mark2[MAX];
int count;
int looper;

void read()
{
    scanf("%d", &n);
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%d", skips + i);
    }
}

int run(int x)
{
    if(mark2[x] == 1)
        return 0;
    if(mark[x] == 1)
    {
        count++;
        looper = x;
        return 1;
    }
    if(mark[x] == 0)
    {
        mark[x] = 1;
        if(run((x + skips[x])%n) == 0)
        {
            mark2[x] = 1;
            return 0;
        }
        if(x == looper)
        {
            mark2[x] = 1;
            return 0;
        }
        count++;
        mark2[x] = 1;
        return 1;
    }

}

void solve()
{
    int i;
    for(i = 0; i < n; i++)
    {
        looper = -999;
        memset(mark, 0, sizeof(int)*n);
        if(mark2[i] == 0)
            run(i);
    }
    printf("%d\n", count);
}

int main()
{
    read();
    solve();
}
