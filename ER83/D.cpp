#include <cstdio>

long long N, M;
long long memo[200001];
#define mod 998244353

long long factorial(long long x) {
    if(x == 0 || x == 1)
        return memo[x] = 1;
    if(memo[x] != 0)
        return memo[x];
    return memo[x] = (x * factorial(x-1))%mod;
}

long long pow(long long x, long long y) {
    long long k = 1;
    while(y) {
        if(y % 2)
            k = (k * x)%mod;
        x = (x * x)%mod;
        y = y >> 1;
    }
    return k;
}

int main() {
    scanf("%lld %lld", &N, &M);
    long long ans = 0;
    if(N > 2) {
        ans = (factorial(M) * pow((factorial(N-1)*factorial(M-N+1))%mod, mod-2))%mod;
        ans = (ans*(N-2))%mod;
        ans = (ans*pow(2, N-3))%mod;
    }
    printf("%lld\n", ans);
    return 0;
}