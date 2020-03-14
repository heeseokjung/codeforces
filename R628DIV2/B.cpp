#include <cstdio>
#include <vector>
#include <set>
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
        set<int> s;
        for(int i = 0; i < N; ++i) {
            if(s.find(v[i]) == s.end())
                s.insert(v[i]);
        }
        printf("%d\n", (int)s.size());
    }
    return 0;
}