#include <cstdio>

int N;
int arr[100000];
int digit[33];

int main() {
    scanf("%d", &N);
    int total = 0;
    for(int i = 0; i < N; ++i) {
        scanf("%d", arr+i);
        int p = 1, pos = 0;
        while(p <= arr[i]) {
            if(p & arr[i])
                digit[pos]++;
            p = p << 1;
            pos++;
        }
    }
    int mx = -1, idx;
    int copy[33];
    for(int i = 0; i < N; ++i) {
        int x = arr[i];
        for(int j = 0; j < 33; ++j)
            copy[j] = digit[j];
        int p = 1, pos = 0;
        while(p <= x) {
            if(p & x)
                copy[pos]--;
            p = p << 1;
            pos++;
        }
        p = 0;
        for(int j = 0; j < 33; ++j) {
            int tmp = 1;
            if(copy[j])
                tmp = tmp << j;
            p = p | tmp;
        }
        if((x & ~p) > mx) {
            mx = x & ~p;
            idx = i;
        }
    }
    printf("%d ", arr[idx]);
    for(int i = 0; i < N; ++i) {
        if(i == idx)
            continue;
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}