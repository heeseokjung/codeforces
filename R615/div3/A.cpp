#include <cstdio>

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int a, b, c, n;
        scanf("%d %d %d %d", &a, &b, &c, &n);
        int sum = a + b + c + n;
        int r = sum % 3;
        int q = sum / 3;
        if(r == 0 && q >= a && q >= b && q >= c)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}