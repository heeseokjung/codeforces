#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int N;
char path[200010];

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N); getchar();
        for(int i = 1; i <= N; ++i)
            scanf("%c", path+i);
        getchar();
        map<pair<int, int>, int> m;
        int x = 0, y = 0;
        m.insert(make_pair(pair<int, int>(x, y), 0));
        int mn = (int)1e9, l, r;
        for(int i = 1; i <= N; ++i) {
            switch(path[i]) {
                case 'L':
                    --x;
                    break;
                case 'R':
                    ++x;
                    break;
                case 'U':
                    ++y;
                    break;
                case 'D':
                    --y;
                    break;
                default:
                    break;
            }
            auto it = m.find(pair<int, int>(x, y));
            if(it != m.end()) {
                int d = i - it->second;
                if(d < mn) {
                    mn = d;
                    l = it->second + 1; r = i;
                }
                it->second = i;
            } else {
                m.insert(make_pair(pair<int, int>(x, y), i));
            }
        }
        if(mn == (int)1e9) {
            printf("-1\n");
        } else {
            printf("%d %d\n", l, r);
        }
    }
    return 0;
}