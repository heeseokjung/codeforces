#include <iostream>
#include <string>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while(TC--) {
        string s;
        cin >> s;
        int size = (int)s.size();
        int p = 0, q = size-1;
        while(p < size && s[p] == '0')
            p++;
        while(q >= 0 && s[q] == '0')
            q--;
        int count = 0;
        for(int i = p; i <= q; ++i) {
            if(i < 0 || i >= size)
                continue;
            if(s[i] == '0')
                count++;
        }
        cout << count << "\n";
    }
    return 0;
}