#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin.tie(0);
    string s, t;
    int n;
    cin >> n;
    while (n--) {
        cin >> s >> t;
        mp[s]++, mp[t]++;
    }
    int mx = -1;
    vector<pair<string, int>> ans;
    for (auto it : mp) {
        if (mx < it.second) {
            mx = it.second;
        }
    }
    for (auto it : mp) {
        if (it.second == mx) {
            ans.push_back({it.first, it.second});
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans[0].first << " " << ans[0].second << " ";
    if(ans.size()!=1)cout << ans .size() <<endl;

}