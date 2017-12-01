#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int n;
int count[MAX];

void read()
{
    scanf("%d", &n);
    int e;
    scanf("%d", &e);
    int i;
    for(i = 0; i < e; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        count[a]++;
        count[b]++;
    }
    for(i = 0; i < n; i++)
    {
        printf("s%d", count[i]);
    }
}

int solve()
{
    int c = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if(count[i]%2 == 1)
            c++;
    }
    return c == 0 || c == 2;
}

int main()
{
    read();
    if(solve())
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}
