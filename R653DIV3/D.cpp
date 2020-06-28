#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<int> v(n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &v[i]);

        map<int, int> m;
        int max_diff = 0, max_count = 0, max_count_diff = 0;
        for(int i = 0; i < n; ++i) {
            if(v[i] % k == 0)
                continue;

            int r = v[i] % k;
            int diff = k - r;
            max_diff = (max_diff < diff ? diff : max_diff);
            
            auto it = m.find(diff);
            if(it == m.end()) {
                m.insert({diff, 1});
                if(max_count == 1) {
                    max_count_diff = (max_count_diff < diff ? diff : max_count_diff);
                } else if(max_count < 1) {
                    max_count = 1;
                    max_count_diff = diff;
                }
            } else {
                it->second++;
                if(max_count == it->second) {
                    max_count_diff = (max_count_diff < diff ? diff : max_count_diff);
                } else if(max_count < it->second) {
                    max_count = it->second;
                    max_count_diff = diff;
                }
            }
        }

        if(max_count == 1)
            printf("%d\n", max_diff + 1);
        else if(max_count > 1)
            printf("%lld\n", (long long)(max_count-1)*(long long)k + (long long)(max_count_diff+1));
        else
            printf("0\n");
    }
    return 0;
}