#include <cstdio>

inline void swap(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int N, M;
        scanf("%d %d", &N, &M);

        if(N > M)
            swap(N, M);

        int sum = (M/2)*N;
        if(M % 2)
            sum += (N/2) + (N%2);
        printf("%d\n", sum);
    }
    return 0;
}