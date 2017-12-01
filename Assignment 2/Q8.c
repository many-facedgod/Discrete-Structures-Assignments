#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#define INF 10000000
int edge_list[MAX][3];
int connected[MAX];
int n;
int e;
int cost = 1;
void read()
{
    scanf("%d", &n);
    scanf("%d", &e);
    int i;
    for(i = 0; i < e; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge_list[i][0] = a;
        edge_list[i][1] = b;
        edge_list[i][2] = c;
    }
    for(i = 0; i < n; i++)
    {
        connected[i] = i;
    }
}

void add_connection(int a, int b)
{
        int temp = connected[a];
	int temp2 = connected[b];
        int i;
        for(i = 0; i < n; i++)
        {
                if(connected[i] == temp2)
                        connected[i] = temp;
        }
}

int check(int a, int b)
{
        return connected[a] == connected[b];
}

int get_min()
{
        int i;
        int min = 0;
        for(i = 1; i < e; i++)
        {
                if(edge_list[i][2] < edge_list[min][2])
                        min = i;
        }
        return min;
}

void solve()
{
        int count = 0;
        while(count != n-1)
        {
                int ind = get_min();
                if(!check(edge_list[ind][0], edge_list[ind][1]))
                {
                        cost *= edge_list[ind][2];
                        add_connection(edge_list[ind][0], edge_list[ind][1]);
                        count++;
                }
                edge_list[ind][2] = INF;
        }
}

int main()
{
        read();
        solve();
        printf("%d\n", cost);
}

