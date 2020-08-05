#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> run(vector<int>& l, vector<int>& r, int N) {
    vector<int> pos(N);
    int l_size = (int)l.size();
    int r_size = (int)r.size();
    int i = 0, j = 0, count = 0;
    while(i < l_size && j < r_size) {
        if(l[i] > r[j]) {
            while(j < r_size && l[i] < r[j]) {
                pos[r[j]] = ++count;
                j++;
            }
        } else {
            pos[l[i]] = count;
            while(i < l_size && l[i] < r[j]) {
                pos[l[i]] = ++count;
                i++;
            }
        }
    }

    while(i < l_size) {
        pos[l[i]] = ++count;
        i++;
    }
    while(j < r_size) {
        pos[r[j]] = ++count;
        j++;
    }

    return pos;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--) {
        int N;
        string s;
        cin >> N >> s;

        vector<int> zero, one;
        for(int i = 0; i < N; ++i) {
            if(s[i] == '0')
                zero.push_back(i);
            else
                one.push_back(i);
        }

        vector<int> pos = run(zero, one, N);

        for(int i = 0; i < N; ++i)
            printf("%d ", pos[i]);
        printf("\n");
    }
    return 0;
}