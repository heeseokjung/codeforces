#include <cstdio>

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        long long x, y, n;
        scanf("%lld %lld %lld", &x, &y, &n);
        long long i = (n-y)/x, k;
        while(true) {
            if(x*i + y <= n) {
                k = x*i + y;
                i++;
            } else {
                break;
            }
            printf("%lld\n", k);
        }
    }
    return 0;
}