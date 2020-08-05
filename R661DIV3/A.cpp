#include <cstdio>
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

        bool imp = false;
        for(int i = 0; i < N-1; ++i) {
            if(v[i+1] - v[i] > 1) {
                imp = true;
                break;
            }
        }

        if(imp)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}