#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        long long x, y, a, b;
        scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
        long long count1 = min(x, y)*b + (max(x, y) - min(x, y))*a;
        long long count2 = a*(x + y);
        printf("%lld\n", (count1 < count2 ? count1 : count2));
    }
    return 0;
}