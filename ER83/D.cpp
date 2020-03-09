#include <cstdio>

int N, M;
#define MOD 998244353

int main() {
    scanf("%d %d", &N, &M);
    long long ans = 1;
    for(int i = 1; i <= M; ++i)
        ans = (ans*M);
    for(int i = 1; i <= N-1; ++i)
        ans /= i;
    for(int i = M-N+1; i >= 1; --i)
        ans /= i;
    printf("%lld\n", ans);
    return 0;
}