#include <cstdio>

int N;
int arr[100000];
int suffix[100001];

int main() {
    scanf("%d", &N);
    int total = 0;
    for(int i = 0; i < N; ++i)
        scanf("%d", arr+i);
    for(int i = N-1; i >= 0; --i)
        suffix[i] = arr[i] | suffix[i+1];
    int mx = -1, mx_pos;
    int prefix = 0;
    for(int i = 0; i < N; ++i) {
        int y = prefix | suffix[i+1];
        if((arr[i] & ~y) > mx) {
            mx = arr[i] & ~y;
            mx_pos = i;
        }
        prefix = prefix | arr[i];
    }
    printf("%d ", arr[mx_pos]);
    for(int i = 0; i < N; ++i) {
        if(i == mx_pos)
            continue;
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}