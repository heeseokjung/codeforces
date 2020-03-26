#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin >> TC;
    while(TC--) {
        int N;
        cin >> N;
        string s;
        cin >> s;

        vector<int> x, y;
        x.reserve(N); y.reserve(N);
        bool check = true;
        for(int i = 0; i < N; ++i) {
            if(s[i] == '0') {
                x.push_back(0);
                y.push_back(0);
            } else if(s[i] == '1') {
                if(check) {
                    x.push_back(1);
                    y.push_back(0);
                    check = false;
                } else {
                    x.push_back(0);
                    y.push_back(1);
                }
            } else if(s[i] == '2') {
                if(check) {
                    x.push_back(1);
                    y.push_back(1);
                } else {
                    x.push_back(0);
                    y.push_back(2);
                }
            }
        }

        for(int i = 0; i < N; ++i)
            cout << x[i];
        cout << "\n";
        for(int i = 0; i < N; ++i)
            cout << y[i];
        cout << "\n";
    }
    return 0;
}