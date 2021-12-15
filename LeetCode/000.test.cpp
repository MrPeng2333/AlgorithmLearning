#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main() {
   unordered_map<int, int> map;
   map[0]++;
   map[2]++;
   map[5]++;
   cout << map.count(5) << endl;
}