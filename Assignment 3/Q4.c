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
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < m; j++)
		{
			if(g2[i][j] && !g1[map[i]][map[j]])
				return 0;
		}
	}
	return 1;
}

int permute(int curr)
{
	if(curr == m)
		return check();
	int i;
	int ans = 0;
	for(i = 0; i < n; i++)
	{
		if(mark[i] == 0)
		{
			map[curr] = i;
			mark[i] = 1;
			ans = ans || permute(curr + 1);
			mark[i] = 0;
		}
	}
	return ans;
}

int solve()
{
	if(m > n || f > e)
		return 0;
	return permute(0);
}

int main()
{
	read();
	if(solve())
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}
