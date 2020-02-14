#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int student[200010];

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        for(int i = 0; i < N*2; ++i)
            scanf("%d", student+i);
        sort(student, student + N*2);
        int pos = (N*2 - 1)/2;
        printf("%d\n", student[pos+1] - student[pos]);
    }
    return 0;
}