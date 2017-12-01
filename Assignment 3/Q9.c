#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 999999
int n;
int e;
int graph[MAX][MAX];
int mult[MAX][MAX];

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
		mult[x][y] = 1;
		mult[y][x] = 1;
	}
}

void multiply()
{
	int i, j, k;	
	int res[n][n];
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			int sum = 0;
			for(k = 0; k < n; k++)
			{
				sum += graph[i][k] * mult[k][j];
			}
			res[i][j] = sum;
		}
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			mult[i][j] = res[i][j];
		}
	}

}

void solve()
{
	multiply();
	multiply();
	int i, sum = 0;
	for(i = 0; i < n; i++)
		sum += mult[i][i];	
	printf("%d\n", sum / 6);
}
int main()
{
	read();
	solve();
}
