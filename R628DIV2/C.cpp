#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int N;
vector<pair<int, int> > adj[100001];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N-1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(pair<int, int>(v, -1));
    }
    return 0;
}