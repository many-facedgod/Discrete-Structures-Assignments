#include <stdio.h>
#include <stdlib.h>
#define MAX 30
int n;
int e;
int m;
int f;
int g1[MAX][MAX];
int g2[MAX][MAX];
int map[MAX];
int mark[MAX];
int count;

void read()
{
	scanf("%d", &n);
	scanf("%d", &e);
	int i;
	for(i = 0; i < e; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		g1[x][y] = 1;
		g1[y][x] = 1;
	}
	scanf("%d", &m);
	scanf("%d", &f);
	for(i = 0; i < f; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		g2[x][y] = 1;
		g2[y][x] = 1;
	}
}

int check()
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(g1[i][j] != g2[map[i]][map[j]])
				return 0;
		}
	}
	return 1;
}

void print_map()
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d->%d ", i, map[i]);
	}
	printf("\n");
}

void permute(int curr)
{
	if(curr == n && check())
	{
		print_map();
		count++;
	}
	int i;
	int ans = 0;
	for(i = 0; i < n; i++)
	{
		if(mark[i] == 0)
		{
			map[curr] = i;
			mark[i] = 1;
			permute(curr + 1);
			mark[i] = 0;
		}
	}
	
}


void solve()
{
	if( (m != n) || (e != f) )
		return;
	permute(0);
}	

int main()
{
	read();
	solve();
	if(!count)
		printf("No bijection possible.");
	return 0;
}
