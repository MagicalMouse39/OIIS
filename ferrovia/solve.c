#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

size_t solve(size_t N, unsigned J[], unsigned P[]);

int main()
{
    size_t N;
    scanf("%zu", &N);

    unsigned *J = malloc(N * sizeof *J);
    unsigned *P = malloc(N * sizeof *P);

    size_t i;
    for (i = 0; i < N; i++)
    {
        scanf("%u", &J[i]);
    }

    for (i = 0; i < N; i++)
    {
        scanf("%u", &P[i]);
    }

    printf("%zu\n", solve(N, J, P) + 1);

    return 0;
}

unsigned a_to_b(size_t N, unsigned J[], size_t s, size_t e)
{
    unsigned sum_f = 0, sum_b = 0;
    size_t i = s;
    while (i != e)
    {
        sum_f += J[i];

        i++;
        if (i >= N)
            i = 0;
    }
    i = s;
    while (i != e)
    {
        i--;
        if (i >= N)
            i = N - 1;

        sum_b += J[i];
    }

    return sum_f < sum_b ? sum_f : sum_b;
}

unsigned total_bill(size_t N, unsigned J[], unsigned P[], size_t i)
{
    size_t j;
    unsigned sum = 0;
    for (j = 0; j < N; j++)
    {
        sum += a_to_b(N, J, j, i) * P[j];
    }

    return sum;
}

size_t solve(size_t N, unsigned J[], unsigned P[])
{
    unsigned min = UINT_MAX;
    size_t min_i;

    size_t i;
    for (i = 0; i < N; i++)
    {
        unsigned bill = total_bill(N, J, P, i);
        if (bill < min)
        {
            min = bill;
            min_i = i;
        }
    }

    return min_i;
}
