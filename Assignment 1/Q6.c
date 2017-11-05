#include <stdio.h>
#include <stdlib.h>
#define MAX_PREP 100
#define MAX_AXIOMS 100

int antecedents[MAX_AXIOMS][MAX_PREP];
int consequents[MAX_AXIOMS];
int states[MAX_PREP];
int n_prep;
int n_ax;
int counts[MAX_AXIOMS];

void read()
{
    scanf("%d", &n_prep);
    scanf("%d", &n_ax);
    int i, j;
    for(i = 0; i < n_ax; i++)
    {
        int k;
        scanf("%d", &k);
        for(j = 0; j < k; j++)
        {
            int x;
            scanf("%d", &x);
            antecedents[i][x] = 1;
            counts[i]++;
        }
        scanf("%d", consequents + i);
    }
}

void run(int x)
{
    if(states[x] == 1)
        return;
    states[x] = 1;
    int i;
    for(i = 0; i < n_ax; i++)
    {
        if(antecedents[i][x] == 1)
            counts[i]--;
        if(counts[i] == 0)
            run(consequents[i]);
    }

}

void query()
{
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        run(x);
    }
}

void print()
{
    int i;
    for(i = 0; i < n_prep; i++)
    {
        if(states[i] == 1)
            printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    read();
    query();
    print();
}
