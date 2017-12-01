#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 999999
int n;
int e;
int graph[MAX][MAX];

void read()
{
	scanf("%d", &n);
	scanf("%d", &e);
	int i;
	for(i = 0; i < e; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
}

void solve()
{
	printf("%d\n", e + 2 - n);
}

int main()
{
	read();
	solve();
}
