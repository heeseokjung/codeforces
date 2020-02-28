#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
bool used[100];
vector<string> v;

bool is_palindrome(string& s) {
    for(int i = 0, j = M-1; i < j; ++i, --j) {
        if(s[i] != s[j])
            return false;
    }
    return true;
}

bool compare(string& s1, string& s2) {
    for(int i = 0, j = M-1; i < M && j >= 0; ++i, --j) {
        if(s1[i] != s2[j])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    v = vector<string>(N);
    for(int i = 0; i < N; ++i)
        cin >> v[i];
    string head, mid, tail;
    for(int i = 0; i < N; ++i) {
        if(used[i])
            continue;
        for(int j = 0; j < N; ++j) {
            if(i == j || used[j])
                continue;
            if(compare(v[i], v[j])) {
                head = head + v[i];
                tail = v[j] + tail;
                used[i] = used[j] = true;
                break;
            }
        }
    }
    for(int i = 0; i < N; ++i) {
        if(!used[i] && is_palindrome(v[i])) {
            mid = mid + v[i];
            break;
        }
    }
    string ans = head + mid + tail;
    cout << ans.size() << "\n";
    cout << ans << "\n";
    return 0;
}