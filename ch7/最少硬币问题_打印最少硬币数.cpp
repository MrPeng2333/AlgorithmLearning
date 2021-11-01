#include<bits/stdc++.h>
using namespace std;

const int VALUE = 5;
const int MONEY = 251;
int type[VALUE] = {1, 5, 10, 25, 50};
int dp[MONEY] = {0};

void init() {
    int i;
    dp[0] = 0;
    for (i = 1; i <= MONEY; i++)
        dp[i] = INT_MAX;
}

void solve() {
    // 初始化
    init();

    int i, j;
    for (i = 0; i < VALUE; i++)                         // 遍历物品
        for (j = type[i]; j <= MONEY; j++)              // 遍历价值 j = MONEY; j >= type[i]; j--
            dp[j] = min(dp[j], dp[j - type[i]] + 1);    // 状态转移
        
        
}
int main() {
    int s;
    solve();
    while (cin >> s) {
        cout << dp[s] << endl;
    }
    return 0;
}