#include<bits/stdc++.h>
using namespace std;
struct Stone {
    int weight;
    int value;
}stone[1011];
int cap;
int num;
int dp[1011];
void solve() {
    // init array dp
    int i, j;
    for (i = 0; i <= cap; i++)
        dp[i] = 0;
    // compute state
    for (i = 0; i < num; i++)
        for (j = cap; j >= stone[i].weight; j--)
            dp[j] = max(dp[j], dp[j - stone[i].weight] + stone[i].value);
}
void input() {
    scanf("%d%d", &num, &cap);
    int i;
    for (i = 0; i < num; i++)
        scanf("%d%d",&stone[i].weight, &stone[i].value);
}
void printAns() {
    printf("%d\n", dp[cap]);
}
int main() {
    input();
    solve();
    printAns();
    return 0;
}