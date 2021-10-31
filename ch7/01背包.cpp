#include<bits/stdc++.h>
using namespace std;
const int TYPE = 4;
const int maxn = 1011;
int dp[maxn][maxn];
int cap, num;
struct Stone {
    int weight;
    int value;
}stone[maxn];
void init() {
    int i, j;
    for(i = 0; i < maxn; i++) 
        for (j = 0; j < maxn; j++)
            dp[i][j] = 0;
    for(j = stone[0].weight; j <= cap; j++)
        dp[0][j] = stone[0].value;
}
void solve() {
    int i, j, k;
    init();
    for (i = 1; i < num; i++)                           // 遍历物品
        for (j = stone[i].weight; j <= cap; j++)        // 遍历容量
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stone[i].weight] + stone[i].value);
}
void input() {
    cin >> cap >> num;
    int i;
    for (i = 0; i < num; i++)
        cin >> stone[i].value >> stone[i].weight;
}
int main() {
    input();
    solve();
    cout << dp[num - 1][cap] << endl;
    return 0;
}


