#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> v;
int pos[100001];
bool occupy[100000];

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        v = vector<int>(N);
        for(int i = 0; i < N; ++i)
            scanf("%d", &v[i]);

        for(int i = 0; i < N; ++i)
            pos[v[i]] = i;

        bool valid = true;
        int prev = -1;
        for(int i = 1; i < N; ++i) {
            int p = pos[i];
            occupy[p] = true;
            if(prev == N-1 || (p != N-1 && occupy[p+1])) {
                prev = -1;
            } else {
                if(prev != -1 && prev+1 != p) {
                    valid = false;
                    break;
                }
                prev = p;
            }
        }

        if(valid)
            printf("Yes\n");
        else
            printf("No\n");

        for(int i = 1; i <= N; ++i)
            occupy[i] = false;
    }
    return 0;
}