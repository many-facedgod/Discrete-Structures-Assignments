#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int nz = 0;
    int no = 0;
    while(n != 0)
    {
        if(n % 2 == 0)
            nz++;
        else
            no++;
        n /= 2;
    }
    if(nz == no)
        printf("Yes\n");
    else
        printf("No\n");
}
