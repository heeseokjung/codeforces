#include <cstdio>

int M;
long long N;
long long arr[100000];

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%lld %d", &N, &M);
        for(int i = 0; i < N; ++i)
            scanf("%lld", arr+i);
    }
    return 0;
}