#include <cstdio>

int N, M, K;
int arr[3500];

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d %d %d", &N, &M, &K);  
        for(int i = 0; i < N; ++i)
            scanf("%d", arr+i);
    }
    return 0;
}