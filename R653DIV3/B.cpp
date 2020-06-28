#include <cstdio>

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        long long n;
        scanf("%lld", &n);
        long long tmp = n;
        int x = 0, y = 0;
        while(n != 1 && n % 2LL == 0) {
            x++;
            n /= 2LL;
        }
        while(n != 1 && n % 3LL == 0) {
            y++;
            n /= 3LL;
        }
        if(n != 1 || x > y)
            printf("-1\n");
        else
            printf("%d\n", (y-x)+y);
    }
    return 0;
}