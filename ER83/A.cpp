#include <cstdio>

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int N, M;
        scanf("%d %d", &N, &M);
        if(N % M == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}