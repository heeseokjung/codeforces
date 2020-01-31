#include <cstdio>
 
int N, M;
int dp[1020][21];
#define MOD 1000000007
 
int combination(int n, int r) {
    if(n == r)
        return dp[n][r] = 1;
    if(r == 0)
        return dp[n][r] = 1;
    if(dp[n][r] != -1) 
        return dp[n][r];
    return dp[n][r] = (combination(n-1, r-1)%MOD + combination(n-1, r)%MOD)%MOD;
}
 
int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i <= N+2*M-1; ++i)
        for(int j = 0; j <= 2*M; ++j)
            dp[i][j] = -1;
    printf("%d\n", combination(N+2*M-1, 2*M));
    return 0;
}