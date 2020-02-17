#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int N, X;
        scanf("%d %d", &N, &X);
        vector<int> v(N);
        for(int i = 0; i < N; ++i)
            scanf("%d", &v[i]);
        int ans = (int)1e9;
        bool check = false;
        for(int i = 0; i < N; ++i) {
            if(X%v[i] == 0 && X/v[i] < ans) {
                ans = X/v[i];
                check = true;
            }
        }
        if(check) {
            printf("%d\n", ans);
        } else {
            int mx = 0, ans = 0;
            for(int i = 0; i < N; ++i) {
                if(mx < v[i])
                    mx = v[i];
            }
            while(X/2 + (X%2 ? 1 : 0) > mx) {
                X -= mx;
                ans++;
            }
            int k = 2;
            for(int i = 0; i < N; ++i) {
                if(X%v[i] == 0 && X/v[i] < k) {
                    k = X/v[i];
                    break;
                }
            }
            ans += k;
            printf("%d\n", ans);
        }
    }
    return 0;
}