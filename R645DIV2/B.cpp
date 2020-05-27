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

        int i;
        for(i = N-1; i >= 0; --i) {
            if(v[i] <= i + 1) {
                printf("%d\n", i + 2);
                break;
            }
        }
        if(i < 0)
            printf("1\n");
    }
    return 0;
}