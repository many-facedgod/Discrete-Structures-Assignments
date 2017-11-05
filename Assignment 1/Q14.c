#include <stdio.h>
#include <stdlib.h>

int num;

void read()
{
    scanf("%d", &num);
}

int nCk(int n, int k)
{
    if(k > n) return 0;
    if(k*2 > n) k = n - k;
    if(k == 0) return 1;

    int result = n, i;
    for(i = 2; i <= k; i++)
    {
        result *= n - i + 1;
        result /= i;
    }
    return result;
}

void solve()
{
    int left = num, i;
    int count = 0;
    for(i = 0; i < num; i++)
    {
        count += nCk(num, i)*left;
        left --;
    }
    printf("%d\n", count);
}

int main()
{
    read();
    solve();
}
