#include <cstdio>

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int N;
        scanf("%d", &N);
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);

        if(N*(a-b) <= c+d && N*(a+b) >= c-d)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}