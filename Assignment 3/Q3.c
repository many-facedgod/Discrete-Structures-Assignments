#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#define INF 999999
int n;
int graph[MAX][MAX];
int in_blob[MAX];
int start;
int k;

void read()
{
	scanf("%d", &n);
	int e;
	scanf("%d", &e);
	int i;
	for(i = 0; i < e; i++)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		graph[x][y] = z;
		graph[y][x] = z;
	}
	scanf("%d", &start);
	scanf("%d", &k);
	k++;
}

void print_blob()
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(in_blob[i])
			printf("%d ", i);
	}
	printf("\n");
}

int get_next()
{
	int curr = -1;
	int min = INF;
	int i, j;
	for(i = 0; i < n; i++)
	{
		if(!in_blob[i])
			continue;
		for(j = 0; j < n; j++)
		{
			if(in_blob[j] || graph[i][j] == 0)
				continue;
			if(graph[i][j] < min)
			{
				min = graph[i][j];
				curr = j;
			}
		}
	}
	return curr;
}

void solve()
{
	in_blob[start] = 1;
	int i;
	for(i = 0; i < k - 1; i++)
	{
		int next = get_next();
		in_blob[next] = 1;
	}
	print_blob();
}

int main()
{
	read();
	solve();
}
