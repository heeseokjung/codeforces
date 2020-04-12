#include <cstdio>
#include <set>
using namespace std;

int N;
long long arr[200001];
long long prefix[200001];

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
        scanf("%lld", arr+i);
    
    for(int i = 1; i <= N; ++i)
        prefix[i] = prefix[i-1] + arr[i];

    long long count = 0;
    set<long long> s = {0};
    int i = 0, j = 0;
    while(i < N) {
        while(j < N && s.find(prefix[j+1]) == s.end()) {
            ++j;
            s.insert(prefix[j]);
        }
        count += (long long)(j - i);
        s.erase(prefix[i]);
        ++i;
    }
    printf("%lld\n", count);

    return 0;
}