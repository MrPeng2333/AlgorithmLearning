#define lobit(x) ((x) & -(x)) // 找到x二进制数的最后一个1
void add(int x, int d) {
    while (x <= n) {
        tree[x] += d;
        x += lowbit(x);
    }
}
int sum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}