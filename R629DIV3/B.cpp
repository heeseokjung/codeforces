#include <cstdio>
#include <utility>
using namespace std;

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int N, K;
        scanf("%d %d", &N, &K);
        pair<int, int> p(N-1, N);
        for(int i = 1; i < K; ) {
            if(p.first + 1 == p.second) {
                p.first--;
                p.second = N;
                i++;
            } else if(i + (p.second - p.first - 1) < K) {
                i += (p.second - p.first - 1);
                p.second = p.first + 1;
            } else {
                p.second--;
                i++;
            }
        }
        for(int i = 1; i <= N; ++i) {
            if(i == p.first || i == p.second)
                printf("b");
            else
                printf("a");
        }
        printf("\n");
    }
    return 0;
}