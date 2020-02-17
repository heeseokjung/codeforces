#include <cstdio>

int M;
long long N;
long long arr[100000];
int count[64];

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%lld %d", &N, &M);
        long long sum = 0;
        for(int i = 0; i < M; ++i) {
            scanf("%lld", arr+i);
            sum += arr[i];
            int j = 0;
            while((1 << j) < arr[i])
                j++;
            count[j]++;
        }
        if(sum < N) {
            printf("-1\n");
        } else {
            long long p = 1;
            int i = 0, ans = 0;
            while(p < sum) {
                if(p & N) {
                    if(count[i]) {
                        count[i]--;
                    } else {
                        while(p < sum && count[i] == 0) {
                            i++;
                            p = p << 1;
                            ans++;
                        }
                        count[i]--;
                        continue;
                    }
                }
                count[i+1] += count[i]/2;
                p = p << 1;
                i++;
            }
            printf("%d\n", ans);
        }
        for(int i = 0; i < 64; ++i)
            count[i] = 0;
    }
    return 0;
}