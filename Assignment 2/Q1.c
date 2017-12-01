#include <stdio.h>
#include <stdlib.h>
#define MAX 30
int admat[MAX][MAX];
int marked[MAX];
int n;
int path[MAX];
int pointer = 0;
int flag;

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

void traverse(int curr)
{
    if(flag == 1)
        return;
    if(marked[curr])
    {
        if(curr == 0 && pointer == n)
        {
            int i;
            for(i = 0; i < n; i++)
            {
                printf("%d ", path[i]);
            }
            printf("0 \n");
            flag = 1;
        }
        return;
    }
    else
    {
        path[pointer++] = curr;
        marked[curr] = 1;
        int i;
        for(i = 0; i < n; i++)
        {
            if(admat[curr][i] == 1)
                traverse(i);
        }
        marked[curr] = 0;
        pointer--;
    }
}

int main()
{
    read(0);
    traverse(0);
}
