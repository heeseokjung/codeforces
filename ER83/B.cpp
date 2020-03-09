#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
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
        sort(v.begin(), v.end(), greater<int>());
        for(int i = 0; i < N; ++i)
            printf("%d ", v[i]);
        printf("\n");
    }
    return 0;
}