#include <cstdio>

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int s;
        scanf("%d", &s);
        int ans = 0;
        while(s) {
            int x = s;
            while(x % 10 != 0 && x > 10)
                x--;
            ans += x;
            s = s - x + x/10;
        }
        printf("%d\n", ans);
    }
    return 0;
}