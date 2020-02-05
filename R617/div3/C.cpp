#include <cstdio>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

int N;
char path[200010];

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        for(int i = 1; i <= N; ++i)
            scanf("%c", path+i);
        getchar();
        multimap<int, pair<int, int> > m;
        int x = 0, y = 0;
        int mn = 1e9;
        pair<int, int> ans;
        m.insert(make_pair(x, make_pair(y, 0)));
        for(int i = 1; i <= N; ++i) {
            printf("c: %c ", path[i]);
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
            printf("x: %d y: %d\n", x, y);
            bool check = false;
            auto its = m.equal_range(x);
            for(auto it = its.first; it != its.second; ++it) {
                if(it->second.first == y) {
                    check = true;
                    //printf("dup x: %d y: %d pos: %d now: %d\n", x, it->second.first, it->second.second, i);
                    if(mn > i - it->second.second) {
                        mn = i - it->second.second;
                        ans.first = it->second.second;
                        ans.second = i;
                        it->second.second = i;
                    }
                    break;
                }
            }
            if(!check)
                m.insert(make_pair(x, make_pair(y, i)));
        }
        if(mn == 1e9)
            printf("-1\n");
        else
            printf("%d %d\n", ans.first + 1, ans.second + 1);
    }
    return 0;
}