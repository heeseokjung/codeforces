#include <cstdio>

int N;
int arr[300000];

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        for(int i = 0; i < N; ++i)
            scanf("%d", arr+i);
        int p = 0, q = N-1;
        for(int i = 0; i < N && arr[i] >= i; ++i)
            p = i;
        for(int i = N-1; i >= 0 && arr[i] >= N-i-1; --i)
            q = i;
        if(q <= p)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}