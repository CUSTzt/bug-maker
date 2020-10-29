//#include<bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

typedef pair<int, int> pii;
const int N = 2510;

pii cows[N];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = n - 1; i >= 0; i--) cin >> cows[i].first >> cows[i].second;
    sort(cows, cows + n);
    map<int, int> spfs;
    for (int i = 0; i < m; i++) {
        int spf, cover;
        cin >> spf >> cover;
        spfs[spf] += cover;
    }
    int res = 0;
    spfs[0] = spfs[1001] = n;
    for (int i = n - 1; i >= 0; i--) {
        auto cow = cows[i];
        auto it = spfs.upper_bound(cow.second);
        it--;
        if (it->first >= cow.first && it->first <= cow.second) {
            res++;
            if (--it->second == 0) spfs.erase(it);
        }
    }
    cout << res;
}