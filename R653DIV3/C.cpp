#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int count = 0, move = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') {
                count++;
            } else {
                if(count != 0) {
                    count--;
                } else {
                    move++;
                    s = s.substr(0, i) + s.substr(i+1, n-i-1) + ')';
                    i--;
                }
            }
        }

        cout << move << "\n";
    }
    return 0;
}