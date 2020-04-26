#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        long long a, b, q;
        scanf("%lld %lld %lld", &a, &b, &q);
        vector<pair<long long, long long> > query(q);
        for(int i = 0; i < q; ++i)
            scanf("%lld %lld", &query[i].first, &query[i].second);

        
    }
    return 0;
}