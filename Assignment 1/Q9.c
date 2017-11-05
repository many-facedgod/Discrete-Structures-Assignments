#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int flag = 0;
    for(i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if(temp % 2 == 0)
            flag = 1;
    }
    if(flag)
        printf("Uatu\n");
    else
        printf("Galactus\n");
}
