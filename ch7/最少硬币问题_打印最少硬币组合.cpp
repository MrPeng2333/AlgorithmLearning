#include<bits/stdc++.h>
using namespace std;

const int MONEY = 251;
const int VALUE = 5;
int type[VALUE] = {1, 5, 10, 25, 50};
int dp[MONEY];
int path[MONEY];
void init() {
    int i;
    dp[0] = 0;
    for (i = 1; i < MONEY; i++)
        dp[i] = INT_MAX;
}
void solve() {
    init();
    int i, j;
    for (i = 0; i < VALUE; i++)                 // 遍历物品
        for (j = type[i]; j < MONEY; j++) {     // 遍历价值
            int tmp = dp[j - type[i]] + 1;
            if (dp[j] > tmp) {
                dp[j] = tmp;
                path[j] = type[i];              // 记录当前组合的最后一个硬币
            }
        }
            
}
void printSolution(int s) {
    if (s == 0) return;
    printSolution(s - path[s]);
    printf("%d ", path[s]);
}
int main() {
    int s;
    solve();
    while (cin >> s) {
        printf("最少硬币数：%d\n", dp[s]);
        printf("最少硬币方案：");
        printSolution(s);
        printf("\n");
    }
    return 0;
}