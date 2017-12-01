#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
#define MAX2 10
int marked[MAX];
int path[MAX];
int point;
int coeff[MAX2][2];
int mod;
int n;
int start;
int end;
int found;

void read()
{
	scanf("%d", &mod);
	scanf("%d", &n);
	int i;
	for(i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		coeff[i][0] = a;
		coeff[i][1] = b;
	}
	
	scanf("%d", &start);
	scanf("%d", &end);
}

void print_path()
{
	int i;
	int curr = start;
	for(i = 0; i < point; i++)
	{
		curr = (coeff[path[i]][0] * curr + coeff[path[i]][1]) % mod;
		printf("%d %d\n", path[i], curr);
	}
	
}

void dfs(int curr)
{
	if(curr == end)
	{
		print_path();
		found = 1;
		printf("*******\n");
		return;
	}
	int i;
	for(i = 0; i < n; i++)
	{
		int next = (curr * coeff[i][0] + coeff[i][1]) % mod;
		if(marked[next])
			continue;
		marked[next] = 1;
		path[point++] = i;
		dfs(next);
		marked[next] = 0;
		point--;
	}
}

void solve()
{
	marked[start] = 1;
	dfs(start);
	if(!found)
		printf("No path possible.\n");
}

int main()
{
	read();
	solve();
}
