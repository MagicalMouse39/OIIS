#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned linear_solve(unsigned T[], size_t N);

int main()
{
    size_t N;

    scanf("%zu", &N);
    unsigned *T = malloc(N * sizeof *T);

    size_t i;
    for (i = 0; i < N; i++) {
        scanf("%u", &T[i]);
    }

    printf("%u\n", linear_solve(T, N));
}

unsigned linear_solve(unsigned T[], size_t N)
{
    unsigned results[3] = {0, 0, 0};
    size_t i;
    for (i = N-2; i < N+1; i--) {
        results[2] = results[1];
        results[1] = results[0];
        unsigned s0 = T[i] + results[1];
        unsigned s1 = T[i+1] + results[2];
        results[0] = s0 < s1 ? s0 : s1;
    }
    return results[0];
}
