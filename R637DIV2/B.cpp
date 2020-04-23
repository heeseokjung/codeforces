#include <cstdio>
#include <vector>
using namespace std;

int N, K;
vector<int> v;
bool peak[200001];
int sum_peak[200001];

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d %d", &N, &K);
        v = vector<int>(N+1);
        for(int i = 1; i <= N; ++i)
            scanf("%d", &v[i]);

        for(int i = 2; i <= N-1; ++i) {
            if(v[i] > v[i-1] && v[i] > v[i+1])
                peak[i] = true;
        }

        for(int i = 1; i <= N; ++i) {
            sum_peak[i] = sum_peak[i-1];
            if(peak[i])
                sum_peak[i]++;
        }

        int max_part = 0, left_border = 0;
        for(int i = 1; i <= N-K+1; ++i) {
            int p = sum_peak[i+K-1] - sum_peak[i-1];
            if(peak[i])
                p--;
            if(peak[i+K-1])
                p--;
            if(p+1 > max_part) {
                max_part = p+1;
                left_border = i;
            }
        }
        printf("%d %d\n", max_part, left_border);
        
        for(int i = 1; i <= N; ++i)
            peak[i] = false;
    }
    return 0;
}