#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Book {
    int t, a, b;
};

inline bool cmp(struct Book& x, struct Book& y) {
    return x.t < y.t;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<struct Book> v(n);
    int alice = 0, bob = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d %d %d", &v[i].t, &v[i].a, &v[i].b);
        if(v[i].a)
            alice++;
        if(v[i].b)
            bob++;
    }

    if(alice < k || bob < k) {
        printf("-1\n");
    } else {
        sort(v.begin(), v.end(), cmp);
        alice = 0, bob = 0;
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            if(alice >= k && bob >= k)
                break;
            if(v[i].a == 1 && v[i].b == 1) {
                alice = (alice < k ? alice + 1 : alice);
                bob = (bob < k ? bob + 1 : bob);
                sum += v[i].t;
            } else if(v[i].a == 1 && v[i].b == 0) {
                alice = (alice < k ? alice + 1 : alice);
                sum += v[i].t;
            } else if(v[i].a == 0 && v[i].b == 1) {
                bob = (bob < k ? bob + 1 : bob);
                sum += v[i].t;
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}