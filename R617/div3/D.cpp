#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b, k;
vector<int> monster;
vector<int> v;

int main() {
    scanf("%d %d %d %d", &n, &a, &b, &k);
    monster = vector<int>(n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &monster[i]);
    sort(monster.begin(), monster.end());
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        if(monster[i] <= a) {
            sum++;
        } else {
            int r = monster[i] % (a+b);
            if(r == 0)
                r = a + b;
            v.push_back(r/a + (r%a ? 1 : 0) - 1);
        }
    }
    sort(v.begin(), v.end());
    int size = (int)v.size();
    for(int i = 0; i < size; ++i) {
        if(v[i] <= k) {
            sum++;
            k -= v[i];
        } else {
            break;
        }
    }
    printf("%d\n", sum);
    return 0;
}