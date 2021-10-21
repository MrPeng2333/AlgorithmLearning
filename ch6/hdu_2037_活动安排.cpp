#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;

struct node {
    int start, end;
} record[MAXN];

bool cmp(const node &a, const node &b) {return a.end < b.end;}

int main() {
    int i, n;
    while ((cin >> n) && n) {
        for (i = 0; i < n; i++)
            cin >> record[i].start >> record[i].end;
        sort(record, record + n, cmp);
        int count = 0;
        int lastEnd = -1;
        for (i = 0; i < n; i++) {
            if (record[i].start >= lastEnd) {
                count++;
                lastEnd = record[i].end;
            }
        }
        cout << count << endl;
    }
    
    return 0;
}