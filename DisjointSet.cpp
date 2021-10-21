#include<bits/stdc++.h>
using namespace std;
const int maxn = 1050;
int s[maxn + 1];

void init_set() { // 初始化
    for (int i = 1; i <= maxn; i++)
        s[i] = i;
}
int find_set(int x) { // 查找
    return x == s[x] ? x : find_set(s[x]);
}
void union_set(int x, int y) { // 合并
    x = find_set(x);
    y = find_set(y);
    if (x != y) s[x] = y;
}
int main() {
    int t, n, m, x, y; // t个测试样例组，每个组n个点，m对关系，x、y表示两个点之间的关系
    cin >> t;
    while (t--) {
        cin >> n >> m;
        init_set();
        for (int i = 1; i <= m; i++) {
            cin >> x >> y;
            union_set(x, y);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) 
            if (i == s[i]) ans++;
        cout << ans << endl;
    }
    return 0;
}
