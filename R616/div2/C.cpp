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
        for(int i = 1; i < M; ++i) {
            int tmp = max(arr[1+i], arr[1+N-M+i]);
        }
    }
    return 0;
}