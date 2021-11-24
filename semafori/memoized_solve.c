#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned memoized_solve(unsigned T[], size_t N);

int main()
{
    size_t N;

    scanf("%zu", &N);
    unsigned *T = malloc(N * sizeof *T);

    size_t i;
    for (i = 0; i < N; i++) {
        scanf("%u", &T[i]);
    }

    printf("%u\n", memoized_solve(T, N));
}

unsigned memoized_solve_r(unsigned T[], size_t N, unsigned results[])
{
    if (N < 2) {
        return 0;
    }

    if (results[0] != UINT_MAX) {
        return results[0];
    }

    unsigned s0 = T[0] + memoized_solve_r(T+1, N-1, results+1);
    unsigned s1 = T[1] + memoized_solve_r(T+2, N-2, results+2);

    results[0] = s0 < s1 ? s0 : s1;
    return results[0];
}

unsigned memoized_solve(unsigned T[], size_t N)
{
    unsigned *results = malloc(N * sizeof *results);
    size_t i;
    for (i = 0; i < N; i++) {
        results[i] = UINT_MAX;
    }
    return memoized_solve_r(T, N, results);
}
