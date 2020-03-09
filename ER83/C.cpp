#include <cstdio>
#include <vector>
using namespace std;

bool run(long long x, long long K, int* check) {
    int p = 0;
    while(x) {
        long long r = x % K;
        if(r > 1)
            return false;
        if(r == 1) {
            if(check[p] != 0)
                return false;
            check[p] = 1;
        }
        x /= K;
        p++;
    }
    return true;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int N, K;
        scanf("%d %d", &N, &K);
        vector<long long> v(N);
        for(int i = 0; i < N; ++i)
            scanf("%lld", &v[i]);
        int check[100];
        for(int i = 0; i < 100; ++i)
            check[i] = 0;
        bool is_possible = true;
        for(int i = 0; i < N; ++i) {
            if(!run(v[i], K, check)) {
                is_possible = false;
                break;
            }
        }
        if(is_possible)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}