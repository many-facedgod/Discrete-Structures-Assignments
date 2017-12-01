#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int seq[MAX];
int n;

void read()
{
    scanf("%d", &n);
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &seq[i]);
    }
}

void sort(int start, int num)
{
    int i, j;
    for(i = start; i < start + num; i++)
    {
        for(j = start; j < start + num - 1; j++)
        {
            if(seq[j] < seq[j + 1])
            {
                int temp = seq[j];
                seq[j] = seq[j + 1];
                seq[j + 1] = temp;
            }
        }
    }
}

int check(int start, int num)
{
    int i;
    for(i = start; i < start + num; i++)
    {
        if(seq[i] < 0)
            return 0;
    }
    return 1;
}

int solve()
{
    sort(0, n);
    int i;
    for(i  = 0; i < n - 1; i++)
    {
        int temp = seq[i];
        if(temp > n - i - 1)
            return 0;
        int j;
        for(j = i + 1; j < temp + i + 1; j++)
            seq[j]--;
        if(!check(i+1, n - i - 1))
            return 0;
        sort(i + 1, n - i - 1);
    }
    return 1;
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
