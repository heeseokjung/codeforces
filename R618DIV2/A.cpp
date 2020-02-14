#include <cstdio>

int N;
int arr[100];

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        int sum = 0, product = 1, zero_count = 0;
        for(int i = 0; i < N; ++i) {
            scanf("%d", arr+i);
            sum += arr[i];
            product *= arr[i];
            if(arr[i] == 0)
                zero_count++;
        }
        int ans = zero_count;
        if(sum + zero_count == 0)
            ans++;
        printf("%d\n", ans);
    }
    return 0;
}