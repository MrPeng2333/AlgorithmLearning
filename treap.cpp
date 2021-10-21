#include<bits/stdc++.h>
using namespace std;

void rotate(Node* &o, int d) {  // d = 0，左旋转；d = 1，右旋转
    Node *k = o->son[d ^ 1];    // d ^ 1 与 1 - d 等价，但是更快；son[0]是左儿子，son[1]是右儿子
    o->son[d ^ 1] = k->son[d];
    k->son[d] = o;
    o = k;
}

int main() {

    return 0;
}