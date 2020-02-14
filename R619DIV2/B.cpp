#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[100000];
vector<pair<int, int> > v;

inline long long absl(long long x) {
    return x < 0 ? -x : x;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        int count = 0;
        for(int i = 0; i < N; ++i) {
            scanf("%d", arr+i);
            if(arr[i] != -1) {
                count++;
                v.push_back(pair<int, int>(arr[i], i));
            }
        }
        if(count == 0) {
            printf("0 %d\n", 42);
        } else if(count == 1) {
            printf("0 %d\n", v[0].first);
        } else {
            sort(v.begin(), v.end());
            //printf("v[0].first: %d v[count-1].first: %d count: %d\n", v[0].first, v[count-1].first, count);
            long long k = 0;
            for(int i = 0; i < count; ++i)
                k += v[i].first;
            k = k / (long long)count;
            long long m = 0;
            for(int i = 0; i < N-1; ++i) {
                long long x = (long long)(arr[i] == -1 ? k : arr[i]);
                long long y = (long long)(arr[i+1] == -1) ? k : arr[i+1];
                long long diff = absl(x - y);
                m = (m < diff) ? diff : m; 
            }
            //printf("v: ");
            //for(int i = 0; i < count; ++i)
            //    printf("%d ", v[i].first);
            //printf("\n");
            printf("%lld %lld\n", m, k);
        }
        v.clear();
    }
    return 0;
}