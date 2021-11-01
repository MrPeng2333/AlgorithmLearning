#include<bits/stdc++.h>
using namespace std;
const int maxn = 1011;
int arr[maxn];
int len;
int dp[maxn];
void LIS() {
    // init arr and len
    scanf("%d", &len);
    int i, j;
    for (i = 0; i < len; i++) 
        scanf("%d", &arr[i]);
    // init dp
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int ans = 1;
    for (i = 2; i < len; i++) {
        int max = 0;
        for (j = 0; j < i; j++)
            if (dp[j] > max && arr[j] < arr[i])
                max = dp[j];
        dp[i] = max + 1;
        if (dp[i] > ans) ans = dp[i];
    }
    printf("%d\n", ans); 
}

int main() {
    LIS();
    return 0;
}