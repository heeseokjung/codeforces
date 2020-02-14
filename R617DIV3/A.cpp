#include <cstdio>

int N;
int arr[2000];

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        int odd = 0, even = 0;
        for(int i = 0; i < N; ++i) {
            scanf("%d", arr+i);
            if(arr[i] % 2)
                odd++;
            else
                even++;
        }

        if(odd == 0) {
            printf("NO\n");
        } else if(odd % 2) {
            printf("YES\n");
        } else {
            if(even == 0)
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
    return 0;
}