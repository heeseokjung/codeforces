#include <cstdio>

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int N, M;
        scanf("%d %d", &N, &M);
        printf("W");
        for(int i = 1; i < M; ++i)
            printf("B");
        printf("\n");
        for(int i = 1; i < N; ++i) {
            for(int j = 0; j < M; ++j)
                printf("B");
            printf("\n");
        }
    }
    return 0;
}