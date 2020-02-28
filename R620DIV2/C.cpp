#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int N, M;
        scanf("%d %d", &N, &M);
        vector<pair<int, pair<int, int> > > v(N);
        for(int i = 0; i < N; ++i)
            scanf("%d %d %d", &v[i].first, &v[i].second.first, &v[i].second.second);
        int prev = 0;
        bool is_possible = true;
        for(int i = 0, j = M, k = M; i < N; ++i) {
            int t = v[i].first;
            int l = v[i].second.first;
            int r = v[i].second.second;
            j -= t - prev;
            k += t - prev;
            prev = t;
            if(j <= r && k >= l) {
                j = max(j, l);
                k = min(k, r);
            } else {
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