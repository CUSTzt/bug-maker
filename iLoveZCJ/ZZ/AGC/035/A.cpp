#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    if (cnt[0] == n) {
        cout << "Yes" << '\n';
        return 0;
    }
    if (n % 3 != 0) {
        cout << "No" << '\n';
        return 0;
    }
    vector<int> all;
    for (auto& p : cnt) {
        for (int i = 0; i < p.second / (n / 3); i++) {
            all.push_back(p.first);
        }
    }
    if (all.size() == 3 && (all[0] ^ all[1] ^ all[2]) == 0) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
    return 0;
}
