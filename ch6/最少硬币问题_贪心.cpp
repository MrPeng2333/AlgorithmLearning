#include<bits/stdc++.h>
using namespace std;

const int NUM = 3;
const int Value[NUM] = {2, 3, 5};

int main() {
    int i, money;
    int ans[NUM] = {0};
    cin >> money;
    for (i = NUM - 1; i >= 0; i--) {
        ans[i] = money / Value[i];
        money = money - ans[i] * Value[i];
    }

    for (i = NUM - 1; i >= 0; i--)
        cout << Value[i] << "元硬币数量：" << ans[i] << endl;

    return 0;
}