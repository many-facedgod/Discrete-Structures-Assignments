#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    scanf("%d", &x);
    int y;
    scanf("%d", &y);
    x = x % 10;
    if(x == 0)
    {
        printf("0\n");
        return;
    }
    if(y == 0)
    {
        printf("1\n");
        return;
    }
    int z = x;
    int i;
    for(i = 0; i < y - 1; i++)
    {
        x = (x * z) % 10;
    }
    printf("%d\n", x);
}
