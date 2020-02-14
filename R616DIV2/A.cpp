#include <cstdio>

int N;
int digit[3010];

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N); getchar();
        char c;
        int odd = 0;
        for(int i = 0; i < N; ++i) {
            scanf("%c", &c);
            digit[i] = c - '0';
            if(digit[i] % 2)
                ++odd;
        }
        getchar();
        if(odd > 1) {
            for(int i = 0, j = 0; i < N && j < 2; ++i) {
                if(digit[i] % 2) {
                    printf("%d", digit[i]);
                    j++;
                }
            }
            printf("\n");
        } else {
            printf("-1\n");
        }
    }
    return 0;
}