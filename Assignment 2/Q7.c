#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#define INF 100000000
int dist[MAX][MAX];
int coor[MAX][2];
int marked[MAX];
int n;
int k;

int get_dist(int a, int b)
{
    if(a == b)
        return 0;
    return (coor[a][0] - coor[b][0])*(coor[a][0] - coor[b][0]) + (coor[a][1] - coor[b][1])*(coor[a][1] - coor[b][1]);
}

void read()
{
    scanf("%d", &n);
    int i;
    for(i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        coor[i][0] = a;
        coor[i][1] = b;
    }
    scanf("%d", &k);
    for(i = 0; i < n; i++)
    {
        int j;
        for(j = 0; j < n; j++)
        {
            dist[i][j] = get_dist(i, j);
        }
        marked[i] = i;
    }
    for(i = 0; i < n; i++)
        dist[i][i] = INF;
}

void add_connection(int a, int b)
{
    int i;
    int temp = marked[b];
    for(i = 0; i < n; i++)
    {
        if(marked[i] == temp)
            marked[i] = marked[a];
    }
}

int get_min()
{
    int i;
    int min = 0;
    for(i = 1; i < n*n; i++)
    {
        if(dist[i/n][i%n] < dist[min/n][min%n])
            min = i;
    }
    return min;
}

int check(int a, int b)
{
    return marked[a] == marked[b];
}

void solve()
{
    int count = 0;
    while(count != n - k)
    {
        int ind = get_min();
        int a = ind / n;
        int b = ind % n;
        if(!check(a, b))
        {
            add_connection(a, b);
            count++;
        }
        dist[a][b] = INF;

    }
}

void print()
{
    int i, j;
    for(i = 0; i < k; i++)
    {
        int curr = -1;
        for(j = 0; j < n; j++)
        {
            if(marked[j] == -1)
                continue;
            if (curr == -1)
            {
                curr = marked[j];
                printf("%d ", j);
                marked[j] = -1;
            }
            else if(curr == marked[j])
            {
                printf("%d ", j);
                marked[j] = -1;
            }
        }
        printf("\n");
    }
}


int main()
{
    read();
    solve();
    print();
}
