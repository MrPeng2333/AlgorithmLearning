#include<bits/stdc++.h>
using namespace std;
// 用结构体建树
const int maxn = 10000;
struct{ 
    int l, r, len;
} tree[4 * maxn];
void BuildTree(int left, int right, int u) {
    tree[u].l = left;
    tree[u].r = right;
    tree[u].len = right - left + 1;
    if (left == right) return;
    BuildTree(left, (left + right) >> 1, u << 1);
    BuildTree(((left + right) >> 1) + 1, right, (u << 1) + 1);
}
// 用完全二叉树构建线段树
int tree[4 * maxn] = {0};
void BuildTree(int n, int last_left) { // last_left = 1 << (int(log(n) / log(2)) + 1)
    int i;
    for (i = last_left; i < last_left + n; i++) 
        tree[i] = 1;
    while (last_left != 1) {
        for (i = last_left / 2; i < last_left; i++)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        last_left = last_left / 2;
    }
}
int main() {

    return 0;
}