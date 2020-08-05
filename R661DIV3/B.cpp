#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int N;
        scanf("%d", &N);
        vector<pair<int, int> > v(N);
        int min_a = (int)1e9, min_b = (int)1e9;
        for(int i = 0; i < N; ++i) {
            scanf("%d", &v[i].first);
            min_a = (min_a > v[i].first ? v[i].first : min_a);
        }
        for(int i = 0; i < N; ++i) {
            scanf("%d", &v[i].second);
            min_b = (min_b > v[i].second ? v[i].second : min_b);
        }

        long long count = 0;
        for(int i = 0; i < N; ++i) {
            if(v[i].first > min_a && v[i].second > min_b) {
                int diff = min(v[i].first - min_a, v[i].second - min_b);
                v[i].first -= diff;
                v[i].second -= diff;
                count += (long long)diff;
            }
            if(v[i].first > min_a) {
                count += (long long)(v[i].first - min_a);
                v[i].first = min_a;
            }
            if(v[i].second > min_b) {
                count += (long long)(v[i].second - min_b);
                v[i].second = min_b;
            }
        }

        printf("%lld\n", count);
    }
    return 0;
}