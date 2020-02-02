#include <cstdio>

int N;
int arr[30000];

inline int abs(int x) {
    return (x < 0) ? -x : x;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        for(int i = 0; i < N; ++i)
            scanf("%d", arr+i);
        int p = 0;
        while(p+1 < N && arr[p] < arr[p+1])
            p++;
        int q = N-1;
        while(q > 0 && arr[q] < arr[q-1])
            q--;
        printf("p: %d q: %d\n", p, q);
        if(N == 1 || p == N-1 || q == 0) {
            printf("Yes\n");
            continue;
        }
        int diff = abs(arr[p] - arr[q]);
        int dist = abs(p - q);
        if(diff >= dist)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}