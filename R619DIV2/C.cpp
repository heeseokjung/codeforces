#include <cstdio>

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int N, M;
        scanf("%d %d", &N, &M);
        long long ans = 0;
        long long x = N;
        for(int i = 1, j; i <= M; ++i) {
            j = (1 << i);
            x = x/j + (x%j ? 1 : 0);
            ans += (long long)x*x*i;
        }
        printf("%lld\n", ans);
    }
    return 0;
}