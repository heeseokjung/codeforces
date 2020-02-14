#include <cstdio>

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int n, d;
        scanf("%d %d", &n, &d);
        if(d <= n) {
            printf("YES\n");
        }
        else {
            int x = 1;
            while((x+1)*(x+1) < d)
                ++x;
            int day = x + d/(x+1) + (d%(x+1) ? 1 : 0);
            if(day <= n)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}