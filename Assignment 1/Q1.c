#include <stdio.h>
#include <stdlib.h>
#define MAX_PART_SIZE 30
#define MAX_NUM_PART 10
typedef struct partition
{
    int n;
    int elems[MAX_PART_SIZE];
} partition;

typedef struct parted_set
{
    int n;
    partition parts[MAX_NUM_PART];
} parted_set;

void read(parted_set* set)
{
    scanf("%d", &(set->n));
    int i;
    for(i = 0; i < set->n; i++)
    {
        scanf("%d", &(set->parts[i].n));
        int j;
        for(j = 0; j < set->parts[i].n; j++)
        {
            scanf("%d", &(set->parts[i].elems[j]));
        }
    }
}

int pow2(int x)
{

    return 1 << x;
}

void part_print(parted_set* set, int partition, int bitstring)
{
    printf("%d ", set->parts[partition].elems[0]);
    int ind;
    int temp = bitstring;
    for(ind = 1; ind < set->parts[partition].n; ind++)
    {
        if(temp%2 == 0)
            printf("%d ", set->parts[partition].elems[ind]);
        temp /= 2;
    }
    printf("\n");
    temp = bitstring;
    for(ind = 1; ind < set->parts[partition].n; ind++)
    {
        if(temp%2 == 1)
            printf("%d ", set->parts[partition].elems[ind]);
        temp /= 2;
    }
    printf("\n");
}

void refine(parted_set* set, int partition)
{
    if(set->parts[partition].n == 1)
        return;
    int k = pow2(set->parts[partition].n - 1);
    int z, i, j;
    for(z = 1; z < k; z++)
    {
        for(i = 0; i < partition; i++)
        {
            for(j = 0; j < set->parts[i].n; j++)
                printf("%d ", set->parts[i].elems[j]);
            printf("\n");
        }
        part_print(set, partition, z);
        for(i = partition + 1; i < set->n; i++)
        {
            for(j = 0; j < set->parts[i].n; j++)
                printf("%d ", set->parts[i].elems[j]);
            printf("\n");
        }
        printf("**************************\n");
    }
}

void print_refinements(parted_set* set)
{
    int i;
    for(i = 0; i < set->n; i++)
    {
        refine(set, i);
    }
}

void print_set(parted_set* set)
{
    int i, j;
    for(i = 0; i < set->n; i++)
    {
        for(j = 0; j < set->parts[i].n; j++)
            printf("%d ", set->parts[i].elems[j]);
        printf("\n");
    }
}

int main()
{
    parted_set set;
    read(&set);
    printf("Original:\n");
    print_set(&set);
    printf("**************************\n");
    printf("**************************\n");
    print_refinements(&set);
    return 0;

}
