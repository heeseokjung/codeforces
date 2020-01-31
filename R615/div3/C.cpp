#include <cstdio>

int main() {
    int TC, N;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        int a, b, c;
        bool valid = false;
        for(a = 2; a*a <= N; ++a) {
            if(N % a == 0)
                break;
        }
        for(b = a+1; b*b <= N/a; ++b) {
            if((N/a) % b == 0)
                break;
        }
        if(b > a && N/(a*b) > b) {
            c = N/(a*b);
            printf("YES\n");
            printf("%d %d %d\n", a, b, c);
        } else {
            printf("NO\n");
        }
    }
    return 0;
}