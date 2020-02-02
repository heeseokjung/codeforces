#include <cstdio>

int N;
int digit[3010];
bool check[3010];

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N); getchar();
        char c;
        for(int i = 0; i < N; ++i) {
            scanf("%c", &c);
            digit[i] = c - '0';
        }
        getchar();

        int even = 0, odd = 0;
        for(int i = 0; i < N; ++i) {
            if(digit[i] % 2 == 0)
                ++even;
            else
                ++odd;
            check[i] = true;
        }

        for(int i = N-1; i > 0 && (digit[i] % 2 == 0); --i) {
            --N;
            --even;
        }

        if(odd % 2) {
            for(int i = N-2; i >= 0; --i) {
                if(digit[i] % 2) {
                    check[i] = false;
                    odd--;
                    break;
                }   
            }
            bool tmp = false;
            for(int i = 0; i < N-1; ++i) {
                if(check[i]) {
                    if(tmp && digit[i] != 0) {
                        tmp = true;
                    }
                    if(!tmp && digit[i] == 0) {
                        even--;
                        check[i] = false;
                    }
                }
            }
        }

        if(odd + even <= 0) {
            printf("-1\n");
        } else {
            int sum = 0;
            for(int i = 0; i < N; ++i) {
                if(check[i])
                    sum += digit[i];
            }
            if(sum % 2 == 0 && digit[N-1] % 2 != 0) {
                for(int i = 0; i < N; ++i) {
                    if(check[i])
                        printf("%d", digit[i]);
                }
                printf("\n");
            } else {
                printf("-1\n");
            }
        }

    }
    return 0;
}