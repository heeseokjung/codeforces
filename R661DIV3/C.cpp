#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int N;
        scanf("%d", &N);
        vector<int> w(N);
        for(int i = 0; i < N; ++i)
            scanf("%d", &w[i]);

        if(N == 1) {
            printf("0\n");
            continue;
        }

        int k = 1;
        map<int, vector<int> > m;
        for(int i = 0; i < N-1; ++i) {
            for(int j = i+1; j < N; ++j) {
                auto it = m.find(w[i] + w[j]);
                if(it == m.end()) {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    m.insert({w[i] + w[j], v});
                } else {
                    bool dup = false;
                    for(int idx : it->second) {
                        if(idx == i || idx == j) {
                            dup = true;
                            break;
                        }
                    }
                    if(!dup) {
                        it->second.push_back(i);
                        it->second.push_back(j);
                        int size = (int)it->second.size() / 2;
                        k = (k < size ? size : k);
                    }
                }
            }
        }

        printf("%d\n", k);
    }
    return 0;
}