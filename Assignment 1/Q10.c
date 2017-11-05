#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int p_one = 0;
    int n_one = 0;
    int other = 0;
    for(i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if(temp == 1)
            p_one = 1;
        else if(temp == -1)
            n_one++;
        else if(temp != 0)
            other ++;
    }
    if((!(n_one && other))&&(!(other > 1))&&(!(n_one > 1 && p_one == 0)))
        printf("Yes\n");
    else
        printf("No\n");
}
