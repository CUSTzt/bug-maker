// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;

void up() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    int cnt = 0;
    vector<int> ans, seq[2];
    for (auto c : s) {
        int x = c - '0';
        if (seq[!x].empty()) {
            seq[x].push_back(++cnt);
            ans.push_back(cnt);
        } else {
            ans.push_back(seq[!x].back());
            seq[x].push_back(seq[!x].back());
            seq[!x].pop_back();
        }
    }
    cout << cnt << endl;
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--) up();
    return 0;
}