#include <cstdio>
#include <vector>
#include <set>
using namespace std;
 
int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int N, K;
        scanf("%d %d", &N, &K);
        vector<int> v(N);
        for(int i = 0; i < N; ++i)
            scanf("%d", &v[i]);

        set<int> s;
        vector<int> period;
        for(int i = 0; i < N; ++i) {
            if(s.find(v[i]) == s.end()) {
                period.push_back(v[i]);
                s.insert(v[i]);
            }
        }

        if(period.size() > K) {
            printf("-1\n");
        } else {
            while((int)period.size() < K)
                period.push_back(1);
            printf("%d\n", N*K);
            for(int i = 0; i < N; ++i) {
                for(int j = 0; j < K; ++j)
                    printf("%d ", period[j]);
            }
            printf("\n");
        }
    }
    return 0;
}