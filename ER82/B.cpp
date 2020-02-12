#include <cstdio>

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        long long N, G, B;
        scanf("%lld %lld %lld", &N, &G, &B);
        int half = N/2 + (N%2 ? 1 : 0);
        if(half % G) {
            long long ans = (G + B)*(half / G) + half % G;
            printf("%lld\n", ans < N ? N : ans);
        } else {
            long long ans = (G + B)*(half / G) - B;
            printf("%lld\n", ans < N ? N : ans);
        }
    }
    return 0;
}