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
        vector<int> v(N);
        for(int i = 0; i < N; ++i)
            scanf("%d", &v[i]);

        sort(v.begin(), v.end());

        vector<pair<int, int> > ans;
        for(int i = 0, j = N-1; i < j; ++i, --j)
            ans.push_back(pair<int, int>(v[i], v[j]));

        if(N % 2)
            printf("%d ", v[N/2]);
        int size = (int)ans.size();
        for(int i = size-1; i >= 0; --i)
            printf("%d %d ", ans[i].first, ans[i].second);
        printf("\n");
    }
    return 0;
}