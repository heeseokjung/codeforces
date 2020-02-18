#include <cstdio>

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        long long N, M;
        scanf("%lld %lld", &N, &M);
        long long total = N*(N + 1)/2LL;
        long long k = (N-M)/(M+1);
        total -= k*(k+1)*(M+1)/2LL;
        total -= (k+1)*((N-M)%(M+1));
        printf("%lld\n", total);
    }
    return 0;
}