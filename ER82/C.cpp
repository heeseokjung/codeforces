#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while(TC--) {
        string s;
        cin >> s;
        bool valid[26];
        for(int i = 0; i < 26; ++i)
            valid[i] = false;
        int size = (int)s.size();
        bool check = false;
        for(int i = 0; i < size; ++i) {
            int j = i-1, k = i+1;
            int count = 0;
            while(j >= 0 && k < size && s[j] == s[k]) {
                --j; ++k;
                count++;
            }
            if(count > 0 && !check) {
                if(j == -1) {
                    check = true;
                    cout << "YES\n";
                    for(int x = j+1; x <= i; ++x) {
                        cout << s[x];
                        valid[s[x]-'a'] = true;
                    }
                    for(char x = 97; x < 97+26; ++x) {
                        if(!valid[x-'a'])
                            cout << x;
                    }
                    cout << "\n";
                } else if(k == size) {
                    check = true;
                    for(int x = i; x <= k-1; ++x) {
                        cout << s[x];
                        valid[s[x]-'a'] = true;
                    }
                    for(char x = 97; x < 97+26; ++x) {
                        if(!valid[x-'a'])
                            cout << x;
                    }
                    cout << "\n";
                }
            }
        }
        if(!check)
            cout << "NO\n";
    }
    return 0;
}