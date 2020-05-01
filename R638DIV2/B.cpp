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
        bool imp = false;
        for(int i = 0; i < N; ++i) {
            if(i < K) {
                s.insert(v[i]);
            } else {
                if(s.find(v[i]) == s.end()) {
                    imp = true;
                    break;
                }
            }
        }
 
        if(imp) {
            printf("-1\n");
        } else {
            vector<int> subarr(K);
            for(int i = 0; i < K; ++i)
                subarr[i] = v[i];
            
            vector<int> ans;
            for(int i = 0, j = 0; i < N; ) {
                if(v[i] == subarr[j%K]) {
                    ans.push_back(v[i]);
                    ++i; ++j;
                } else {
                    ans.push_back(subarr[j%K]);
                    ++j;
                }
            }
 
            printf("%d\n", (int)ans.size());
            for(int i = 0; i < (int)ans.size(); ++i)
                printf("%d ", ans[i]);
            printf("\n");
        }
    }
    return 0;
}