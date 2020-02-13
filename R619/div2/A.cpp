#include <iostream>
#include <string>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while(TC--) {
        string a, b, c;
        cin >> a >> b >> c;
        int size = (int)a.size();
        bool is_possible = true;
        for(int i = 0; i < size; ++i) {
            if(c[i] != a[i] && c[i] != b[i]) {
                is_possible = false;
                break;
            }
        }
        if(is_possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}