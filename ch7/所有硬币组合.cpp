#include<bits/stdc++.h>
using namespace std;
const int MONEY = 251;
const int VALUE = 5;
const int NUM = 101;
int type[VALUE] = {1, 5, 10, 25, 50};
int dp[MONEY][NUM];
void init() {
    int i, j;
    for (i = 0; i < MONEY; i++) 
        for (j = 0; j < NUM; j++)
            dp[i][j] = 0;
    dp[0][0] = 1;

}
void solve() {
    int i, j, k;
    init();
    for (i = 0; i < VALUE; i++)                 // 遍历物品
        for (j = 1; j < NUM; j++)               // 背包容量
            for (k = type[i]; k < MONEY; k++)   // 物品价值
                dp[k][j] += dp[k - type[i]][j-1]; 
}
void printAns(int s) {
    int i, ans = 0;
    for (i = 0; i < NUM; i++)
        ans += dp[s][i];
    printf("%d\n", ans);
}
int main() {
    int s;
    solve();
    while (cin >> s)
        printAns(s);
    return 0;
}