#include <cstdio>

inline int abs(int x) {
    return x < 0 ? -x : x;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int N;
        scanf("%d", &N);

        int total = (1<<(N+1)) - 2;
        int x = 1<<N, y;
        for(int i = 1; i < N/2; ++i)
            x += (1<<i);
        y = total - x;
        
        printf("%d\n", abs(x - y));
    }
    return 0;
}