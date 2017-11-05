#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int arr[MAX];
int num;

int isgood(int* x, int n)
{
    int i, j;
    int count = 0;
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(x[i] % x[j] == 0 || x[j] % x[i] == 0)
                count ++;
        }
    }

    if((count + n) % 2 == 0)
        return 1;
    else
        return 0;
}

void read()
{
    scanf("%d", &num);
    int i;
    for(i = 0; i < num; i++)
        scanf("%d", arr + i);
}

void print(int* x, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}

int get(int* temp, int bit)
{
    int k = 0, i;
    for(i = 0; i < num; i++)
    {
        int mask = 1 << i;
        if((mask & bit) > 0)
            temp[k++] = arr[i];
    }
    return k;
}

void solve()
{
    int m = 1 << num;
    int i;
    int temp[MAX];
    for(i = 1; i < m; i++)
    {
        int n = get(temp, i);
        if(isgood(temp, n))
            print(temp, n);
    }
}

int main()
{
    read();
    solve();
}
