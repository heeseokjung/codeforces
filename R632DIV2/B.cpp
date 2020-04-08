#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> a, b;

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        a.reserve(N); b.reserve(N);
        for(int i = 0; i < N; ++i)
            scanf("%d", &a[i]);
        for(int i = 0; i < N; ++i)
            scanf("%d", &b[i]);

        int num[3] = {0, 0, 0};
        for(int i = 0; i < N; ++i) {
            switch(a[i]) {
                case -1:
                    num[0]++;
                    break;
                case 0:
                    num[1]++;
                    break;
                case 1:
                    num[2]++;
                    break;
                default:
                    break;
            }
        }

        bool check = true;
        for(int i = N-1; i > 0; --i) {
            switch(a[i]) {
                case -1:
                    num[0]--;
                    break;
                case 0:
                    num[1]--;
                    break;
                case 1:
                    num[2]--;
                    break;
                default:
                    break;
            }

            int x = b[i] - a[i];
            if(x == 0) {
                continue;
            } else if(num[0] > 0 && x < 0) {
                continue;
            } else if(num[2] > 0 && x > 0) {
                continue;
            } else {
                check = false;
                break;
            }
        }

        printf((check && a[0] == b[0] ? "YES\n" : "NO\n"));
    }
    return 0;
}