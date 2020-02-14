#include <cstdio>

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        long long count = 0;
        for(int i = 10, j = 1; i-1 <= b; i *= 10, ++j)
            count++;
        printf("%lld\n", a*count);
    }
    return 0;
}