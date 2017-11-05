#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y)
{
    if(x == 0)
        return y;
    return gcd(y%x, x);
}

int rank(int p, int q)
{
    int i;
    int rank =0;
    for(i = 2; i <= p + q; i++)
    {
        int a;
        for(a = 1; a <= i-1; a++)
        {
            if(gcd(a, i-a) == 1)
                rank++;
            if(i%2 == 0)
            {
                if(i-a == p && a == q)
                    break;
            }
            else
            {
                if(a == p && i-a == q)
                    break;
            }
        }
    }
    return rank;
}

int main()
{
    int p, q;
    scanf("%d %d", &p, &q);
    p /= gcd(p, q);
    q /= gcd(p, q);
    printf("%d\n", rank(p, q));
}
