#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 999999
int n;
int graph[MAX][MAX];
int color[MAX];
int queue[MAX];
int point;
void read()
{
	scanf("%d", &n);
	int e;
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

void print_colors()
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(color[i] == 1)
			printf("%d ", i);
	}
	printf("\n");
	for(i = 0; i < n; i++)
	{
		if(color[i] == -1)
			printf("%d ", i);
	}
	printf("\n");
}

int solve()
{
	int i = 0;
	while(i!= point)
	{
		int j;
		for(j = 0; j < n; j++)
		{
			if(graph[queue[i]][j] == 0)
				continue;
			if(color[j] == 0)
			{				
				queue[point++] = j;
				color[j] = -1 * color[queue[i]];
			}
			if(color[j] == color[queue[i]])
				return 0;
		}
		i++;
	}
	return 1;
}

int main()
{
	read();
	color[0] = 1;
	queue[point++] = 0;
	if(!solve())
	{
		printf("Not possible\n");
	}
	else
	{
		print_colors();
	}
}
