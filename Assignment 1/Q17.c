#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int set1[MAX];
int set2[MAX];
int n1;
int n2;

void read()
{
    int nT;
    scanf("%d", &nT);
    int i;
    for(i = 0; i < nT; i++)
        scanf("%*d");
    scanf("%d", &n1);
    for(i = 0; i < n1; i++)
        scanf("%d", set1 + i);
    scanf("%d", &n2);
    for(i = 0; i < n2; i++)
        scanf("%d", set2 + i);
}

int get_subtract(int* s1, int n1, int* s2, int n2, int* result)
{
    int k = 0, i, j;
    for(i = 0; i <n1; i++)
    {
        int temp = s1[i];
        for(j = 0; j < n2; j++)
        {
            if(s2[j] == temp)
                break;
        }
        if(j == n2)
            result[k++] = temp;
    }
    return k;
}
void printset(int* s, int n, int bitstring)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(((1 << i) & bitstring) != 0)
            printf("%d ", s[i]);
    }
}

void solve()
{
    int subtract[MAX];
    int ns = get_subtract(set2, n2, set1, n1, subtract);
    int z = 1 << n1;
    int i, j;
    for(i = 0; i < z; i++)
    {
        for(j = 0; j < ns; j++)
            printf("%d ", subtract[j]);
        printset(set1, n1, i);
        printf("\n");
    }
}

int main()
{
    read();
    solve();
}
