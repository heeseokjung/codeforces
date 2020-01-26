#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool check[32000];
vector<int> prime;

int main()  {
    for(int i = 2; i <= 32000; ++i) {
        if(!check[i]) {
            for(int j = 1; i*j <= 32000; ++j)
                prime.push_back(i*j);
        }
    }
    sort(prime.begin(), prime.end());
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        int size = (int)prime.size();
        int idx = 0, pf = prime[idx];
        int last, tmp = 1;
        vector<pair<int, int> > v;
        while(pf*pf <= N && idx < size) {
            while(N % pf == 0) {
                N /= pf;
                if(v.size() == 0 || v[(int)v.size()-1].first != pf)
                    v.push_back(pair<int, int>(pf, 1));
                else
                    v[(int)v.size()-1].second++;
            }
            pf = prime[++idx];
        }
        if(N != 1) {
            if(v.size() == 0 || v[(int)v.size()-1].first != N)
                v.push_back(pair<int, int>(N, 1));
            else
                v[(int)v.size()-1].second++;
        }
        size = (int)v.size();
        vector<int> ans;
        for(int i = 0; i < size && ans.size() < 3; ++i) {
            int j = v[i].second, k = 1, x = v[i].first;
            //printf("j: %d x: %d\n", j, x);
            while(j > 0) {
                ans.push_back(x);
                x = x*v[i].first;
                ++k;
                j -= k;
            }
        }
        if(ans.size() < 3) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
            for(int i = 0; i < 3; ++i)
                printf("%d ", ans[i]);
            printf("\n");
        }
    }
    return 0;
}