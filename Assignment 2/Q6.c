#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 30
int n;
int connected[MAX];
void read()
{
    scanf("%d", &n);
    int x;
    scanf("%d", &x);
    int i;
    for(i = 0; i < n; i++)
        connected[i] = i;
    for(i = 0; i < x; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int j;
	int temp = connected[b];
        for(j = 0; j < n; j++)
        {
            if(connected[j] == temp)
                connected[j] = connected[a];
        }
    }
}

int check(int a, int b)
{
    return connected[a] == connected[b];
}

int main()
{
        read();
        int a, b;
        scanf("%d %d", &a, &b);
        if(check(a, b))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
}
