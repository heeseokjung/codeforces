#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, K;
int arr[3501];

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d %d %d", &N, &M, &K);  
        for(int i = 1; i <= N; ++i)
            scanf("%d", arr+i);
        int ans = 0;
        int end = min(M-1, K);
        for(int i = 0; i <= end; ++i) {
            int tmp1 = 1e9;
            for(int j = 0; j <= M-1-end; ++j) {
                int tmp2 = max(arr[1+i+j], arr[1+i+j+N-M]);
                tmp1 = (tmp2 < tmp1) ? tmp2 : tmp1;
            }
            ans = (ans < tmp1) ? tmp1 : ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}