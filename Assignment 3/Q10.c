#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 999999
int n;
int e;
int start;
int end;
int graph[MAX][MAX];
int mult[MAX][MAX];
int mark[MAX];
int path[MAX];
int point;
int found;

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
	scanf("%d", &start);
	scanf("%d", &end);
}

void print_path()
{
	int i;
	printf("%d ", start);
	for(i = 0; i < point; i++)
	{
		printf("%d ", path[i]);
	}
	printf("\n");
}

void dfs(int curr)
{
	if(found)
		return;
	if(curr == end)
	{
		print_path();
		found = 1;
		return;
	}
	int i;
	for(i = 0; i < n; i++)
	{
		if(graph[curr][i] == 0)
			continue;
		if(mark[i])
			continue;
		mark[i] = 1;
		path[point++] = i;
		dfs(i);
		if(found)
			return;
		point--;
	}
}
		

void solve()
{
	mark[start] = 1;
	dfs(start);
	if(!found)
		printf("No path exists.\n");
}

int main()
{
	read();
	solve();
}
