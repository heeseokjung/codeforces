#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int> > package;
vector<char> s;

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        package.reserve(N);
        int x, y;
        for(int i = 0; i < N; ++i) {
            scanf("%d %d", &x, &y);
            package.push_back(pair<int, int>(x, y));
        }
        sort(package.begin(), package.end());
        pair<int, int> pos = make_pair(0, 0);
        bool is_possible = true;
        for(int i = 0; i < N; ++i) {
            int x = package[i].first;
            int y = package[i].second;
            if(pos.first > x || pos.second > y) {
                is_possible = false;
                break;
            }
            for(int j = 1; j <= x - pos.first; ++j)
                s.push_back('R');
            for(int j = 1; j <= y - pos.second; ++j)
                s.push_back('U');
            pos.first = x;
            pos.second = y;
        }
        if(is_possible) {
            printf("YES\n");
            for(int i = 0; i < (int)s.size(); ++i)
                printf("%c", s[i]);
            printf("\n");
        }
        else {
            printf("NO\n");
        }
        package.clear();
        s.clear();
    }
    return 0;
}