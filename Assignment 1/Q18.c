#include <stdlib.h>
#include <stdio.h>
#define MAX 100
int arr[MAX];
int n;
int arr2[MAX];
int k;

void read()
{
    scanf("%d", &n);
    int i;
    for(i = 0; i < n; i++)
        scanf("%d", arr + i);
    scanf("%d", &k);
    for(i = 0; i < k; i++)
        arr2[i] = i;
}

void print()
{
    int i;
    for(i = 0; i < k; i++)
        printf("%d ", arr[arr2[i]]);
    printf("\n");
}

void solve()
{
    print();
    while(1)
    {
        int i = k - 1;
        while( i >= 0 && arr2[i] >= n - k + i)
            i--;
        if(i == -1)
            break;
        arr2[i]++;
        int j;
        for(j = i + 1; j < k; j++)
            arr2[j] = arr2[j - 1] + 1;
        print();
    }
}

int main()
{
    read();
    solve();
}
