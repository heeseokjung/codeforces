#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int N;
int count = 0;
vector<pair<int, int> > adj[100001];
int degree[100001];
int ans[100000];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N-1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(pair<int, int>(v, i));
        adj[v].push_back(pair<int, int>(u, i));
        degree[u]++;
        degree[v]++;
    }
    for(int i = 0; i < N-1; ++i)
        ans[i] = -1;
    for(int i = 1; i <= N; ++i) {
        if(degree[i] >= 3) {
            for(int j = 0; j < 3; ++j) {
                int pos = adj[i][j].second;
                ans[pos] = count++;
            }
            break;
        }
    }
    for(int i = 0; i < N-1; ++i) {
        if(ans[i] == -1)
            printf("%d\n", count++);
        else
            printf("%d\n", ans[i]);
    }
    return 0;
}