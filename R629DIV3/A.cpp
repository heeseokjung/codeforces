#include <cstdio>

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a % b == 0) 
            printf("0\n");
        else
            printf("%d\n", b - (a % b));
    }
    return 0;
}