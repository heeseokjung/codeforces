#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--) {
        string t;
        cin >> t;
        if((int)t.size() <= 2) {
            cout << t << "\n";
        } else {
            int num_zero = 0, num_one = 0;
            for(int i = 0; i < (int)t.size(); ++i) {
                if(t[i] == '0')
                    num_zero++;
                else if(t[i] == '1')
                    num_one++;
            }

            if(num_zero == (int)t.size() || num_one == (int)t.size()) {
                cout << t << "\n";
            } else {
                string tmp;
                for(int i = 0; i < (int)t.size()-1; ++i) {
                    if(t[i] != t[i+1]) {
                        tmp = t.substr(i, 2);
                        break;
                    }
                }
                string ans;
                for(int i = 0; i < (int)t.size(); ++i)
                    ans += tmp;
                cout << ans << "\n";
            }
        }
    }

    return 0;
}