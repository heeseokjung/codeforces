#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--) {
        int N;
        cin >> N;
        vector<int> v(N);
        for(int i = 0; i < N; ++i)
            cin >> v[i];

        vector<int> count(200001, 0);
        vector<int> sorted_v;
        for(int i = 0; i < N; ++i) {
            if(count[v[i]] == 0) {
                count[v[i]]++;
                sorted_v.push_back(v[i]);
            } else {
                count[v[i]]++;
            }
        }

        sort(sorted_v.begin(), sorted_v.end());

        long long sum = 1;
        for(int i = 0; i < (int)sorted_v.size(); ) {
            if((long long)sorted_v[i] <= sum + (long long)count[sorted_v[i]] - 1) {
                sum += count[sorted_v[i]];
                i++;
            } else {
                long long cur = 0;
                int j;
                for(j = i; j < (int)sorted_v.size(); ++j) {
                    cur += count[sorted_v[j]];
                    if((long long)sorted_v[j] <= sum + cur - 1) {
                        sum += cur;
                        break;
                    }
                }
                i = j+1;
            }
        }
        
        cout << sum << "\n";
    }
    return 0;
}