#include <stdio.h>
#include <stdlib.h>
long long int partition(int min, int n)
{
	if(n == 0)
	{		
		return 1;
	}
	if(min > n)
	{
		
		return 0;
	}
	
	long long int count = 0;
	for(int i=min; i<=n; i++)
	{
		count += partition(i, n-i);
	}
	
	return count;
}



int main()
{
	int e, m;
	scanf("%d %d", &e, &m);
	printf("%lld\n", partition(m,e));
}
