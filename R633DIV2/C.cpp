#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int N;
        scanf("%d", &N);
        vector<int> v(N);
        for(int i = 0; i < N; ++i)
            scanf("%d", &v[i]);

        int x = v[0];
        long long max_diff = 0;
        for(int i = 1; i < N; ++i) {
            if(v[i] >= x) {
                x = v[i];
            } else {
                long long diff = (long long)x - v[i];
                max_diff = max_diff < diff ? diff : max_diff;
            }
        }

        int p = 0, ans = 0;
        while((1LL<<p) <= max_diff) {
            if((1LL<<p) & max_diff)
                ans = ans < p+1 ? p+1 : ans;
            p++;
        }
        printf("%d\n", ans);
    }
    return 0;
}