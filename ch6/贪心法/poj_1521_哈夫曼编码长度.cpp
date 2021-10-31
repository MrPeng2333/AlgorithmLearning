#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int> > Q;
int main() {
    string s;
    while(getline(cin, s) && s != "END") {
        int t = 1;
        sort(s.begin(), s.end());
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i - 1]) {
                Q.push(t);
                t = 1;
            } else 
                t++;
        }
        Q.push(t);
        int ans = 0;
        while(Q.size() > 1) {
            int a = Q.top(); Q.pop();
            int b = Q.top(); Q.pop();
            ans += (a + b);
            Q.push(a + b);
        }
        Q.pop();
        int ascii = s.length() * 8;
        printf("%d %d %.1f", ascii, ans, ascii * 1.0 / ans);
    }
}