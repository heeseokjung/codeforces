#include <iostream>
#include <string>
using namespace std;

inline int absl(int x) {
    return x < 0 ? -x : x;
}

int main() {
    int TC;
    cin >> TC;
    bool used[26];
    while(TC--) {
        string s;
        cin >> s;
        for(int i = 0; i < 26; ++i)
            used[i] = false;
        int pos = 0;
        string keyboard;
        keyboard = keyboard + s[pos];
        used[s[pos]-'a'] = true;
        bool is_possible = true;
        int size = (int)s.size();
        for(int i = 1; i < size; ++i) {
            if(used[s[i]-'a']) {
                if(pos > 0 && keyboard[pos-1] == s[i]) {
                    pos--;
                } else if(pos < (int)keyboard.size()-1 && keyboard[pos+1] == s[i]) {
                    pos++;
                } else {
                    cout << "NO\n";
                    is_possible = false;
                    break;
                }
            } else {
                if(pos == 0) {
                    keyboard = s[i] + keyboard;
                    used[s[i]-'a'] = true;
                } else if(pos == (int)keyboard.size()-1) {
                    keyboard = keyboard + s[i];
                    pos++;
                    used[s[i]-'a'] = true;
                } else {
                    cout << "NO\n";
                    is_possible = false;
                    break;
                }
            }
        }
        if(is_possible) {
            cout << "YES\n";
            cout << keyboard;
            for(int i = 0; i < 26; ++i) {
                if(!used[i])
                    cout << (char)(i + 'a');
            }
            cout << "\n";
        }
    }
    return 0;
}