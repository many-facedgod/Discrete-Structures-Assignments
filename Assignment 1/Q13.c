#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int relation[MAX][MAX];
int n;

void read()
{
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    int i;
    for(i = 0; i < k; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        relation[x][y] = 1;
    }
}

void complete()
{
    int i, j, k;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            for(k = 0; k < n; k++)
            {
                if(relation[j][i] && relation[i][k])
                    relation[j][k] = 1;
            }
        }
    }

}

void check()
{
    int i, ref = 1;
    for(i = 0; i < n; i++)
    {
        if(relation[i][i] == 0)
            ref = 0;
    }

    if(ref)
        printf("Reflexive\n");
    else
        printf("Not Reflexive\n");
}

int main()
{
    read();
    complete();
    check();

}
