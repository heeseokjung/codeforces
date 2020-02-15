#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[100000];

inline long long absl(long long x) {
    return x < 0 ? -x : x;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        vector<int> v;
        int count = 0;
        for(int i = 0; i < N; ++i)
            scanf("%d", arr+i);
        for(int i = 0; i < N; ++i) { 
            if(arr[i] != -1) {
                count++;
                if(i > 0 && arr[i-1] == -1) {
                    v.push_back(arr[i]);
                }
                else if(i < N-1 && arr[i+1] == -1) {
                    v.push_back(arr[i]);
                }
            }
        }
        if(count == 0) {
            printf("0 42\n");
        } else if(count == 1) {
            printf("0 %d\n", v[0]);
        } else {
            sort(v.begin(), v.end());
            int k = (v[0] + v[(int)v.size()-1]) / 2;
            int m = 0;
            for(int i = 0; i < N-1; ++i) {
                int x = (arr[i] == -1) ? k : arr[i];
                int y = (arr[i+1] == -1) ? k : arr[i+1];
                int diff = absl(x - y);
                m = max(m, diff);
            }
            printf("%d %d\n", m, k);
        }
    }
    return 0;
}