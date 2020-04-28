#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

long long a, b, q;
long long sum[40010];

long long query(long long x) {
    long long count = x / (a*b);
    long long r = x % (a*b);
    return sum[a*b-1]*count + sum[r];
}

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%lld %lld %lld", &a, &b, &q);
        vector<pair<long long, long long> > v(q);
        for(int i = 0; i < q; ++i)
            scanf("%lld %lld", &v[i].first, &v[i].second);

        for(int i = 0; i < a*b; ++i)
            sum[i] = 0;
        for(int i = 0; i < a*b; ++i) {
            sum[i] = (long long)((i%a)%b != (i%b)%a);
            if(i > 0)
                sum[i] += sum[i-1];
        }

        for(int i = 0; i < q; ++i) 
            printf("%lld ", query(v[i].second) - query(v[i].first - 1));
        printf("\n");
    }

    return 0;
}