#include<bits/stdc++.h>
using namespace std;
const int maxn = 1011;
char X[maxn], Y[maxn];

int dp[maxn][maxn];

void LCS() {
    // init arr dp
    memset(dp, 0, sizeof(dp));
    // init X and Y
    scanf("%s%s", X, Y);
    int i, j;
    int lx = strlen(X);
    int ly = strlen(Y);
    for (i = 1; i <= lx; i++)
        for (j = 1; j <= ly; j++)
            dp[i][j] = (X[i - 1] == Y[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]));
    printf("%d\n", dp[lx][ly]);
}


int main() {
    LCS();
    return 0;
}