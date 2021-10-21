const int maxn = 1050;

int s[maxn + 1];
int height[maxn + 1];
void init_set() {
    for (int i = 1; i <= maxn; i++) {
        s[i] = i;
        height[i] = 0;  // 树的高度
    }
}
int find_set(int x) { // 递归路径压缩
    return x == s[x] ? x : s[x] = find_set(s[x]);
}

int find_set(int x) { // 非递归路径压缩
    int r = x;
    while (r != s[r])
        r = s[r];
    int i = x, j;
    while (i != r) {
        j = s[i];
        s[i] = r;
        i = j;
    }
    return r;
}
void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x != y) 
        if (height[x] == height[y]) {
            height[x] = height[x] + 1;
            s[y] = x;
        }
        else 
            height[x] < height[y] ? s[x] = y : s[y] = x;
}
