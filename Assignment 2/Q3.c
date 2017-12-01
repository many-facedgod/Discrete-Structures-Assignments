#include <stdio.h>
#include <stdlib.h>
#define MAX 30
int n;
double p = 0.3;
double admat[MAX][MAX];
int count[MAX];
int iters = 100;
double state[MAX];
void read()
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
        count[a]++;
    }
    for(i = 0; i < n; i++)
    {
        int j;
        for(j = 0; j < n; j++)
        {
            if(count[i] != 0)
                admat[i][j] /= count[i];
            else
                admat[i][j] = 1.0 / n;
        }
    }
}

void iterate()
{
        double temp[n];
        int i;
        for(i = 0; i < n; i++)
        {
                int j;
                double sum = 0.0f;
                for(j = 0; j < n; j++)
                {
                        sum += state[j] * admat[j][i];
                }
                temp[i] = sum;
        }
        for(i = 0; i < n; i++)
        {
                state[i] = temp[i];
        }
}

int main()
{
        read();
        int i;
        state[0] = 1.0;
        for(i = 0; i < iters; i++)
        {
                iterate();
        }
        for(i = 0; i < n; i++)
        {
                printf("%d %lf\n", i, state[i]);
        }
}


