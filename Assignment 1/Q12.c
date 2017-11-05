#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int arr[MAX];
int k;
int num;

void read()
{
    scanf("%d", &num);
}

void factorize()
{
    int factor = 2;
    while(num != 1)
    {

        while(num % factor == 0)
        {
            arr[k]++;
            num /= factor;
        }
        factor++;
        if(arr[k] != 0)
            k++;
    }
}

int get_sum(int left, int start)
{
    if(left == 0)
        return 1;
    int i;
    int sum = 0;
    for(i = start; i <= k - left; i++ )
    {
        sum += arr[i] * get_sum(left - 1, i + 1);
    }
    return sum;
}

void solve()
{
    int i;
    int sum = 0;
    for(i = 1; i <= k; i++)
    {
        sum += i*get_sum(i, 0);
    }
    printf("%d\n", sum);
}

int main()
{
    read();
    factorize();
    solve();
}
