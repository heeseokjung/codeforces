#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int n, d;
        scanf("%d %d", &n, &d);
        vector<int> v(n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &v[i]);
        for(int i = 1; i < n; ++i) {
            if(v[i]) {
                while(d - i >= 0 && v[i]) {
                    d -= i;
                    v[i]--;
                    v[0]++;
                }
            }
            if(d <= 0)
                break;
        }
        printf("%d\n", v[0]);
    }
    return 0;
}