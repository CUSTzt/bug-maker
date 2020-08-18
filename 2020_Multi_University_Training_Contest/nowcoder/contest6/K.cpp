#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <vector>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
    for (T& x : v) is >> x;
    return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    if (!v.empty()) {
        os << v.front();
        for (int i = 1; i < v.size(); ++i) os << ' ' << v[i];
    }
    return os;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        cin >> a;
        unordered_map<int, int> lst;
        bool fl = true;
        int tot = 0;
        vector<pair<int, int>> dif;
        for (int i = 0; i < n; ++i) {
            if (a[i] < 0 || a[i] > k) {
                fl = false;
                break;
            }
            auto it = lst.find(a[i]);
            if (it != lst.end()) {
                if (i - it->second >= k) {
                } else {
                    int l = it->second + 1, r = i;
                    l %= k;
                    r %= k;
                    ++tot;
                    if (l <= r) {
                        dif.emplace_back(l, 1);
                        dif.emplace_back(r + 1, -1);
                    } else {
                        dif.emplace_back(l, 1);
                        dif.emplace_back(k, -1);
                        dif.emplace_back(0, 1);
                        dif.emplace_back(r + 1, -1);
                    }
                }
                it->second = i;
            } else
                lst.insert(make_pair(a[i], i));
        }
        if (!fl)
            cout << "NO\n";
        else {
            if (tot == 0)
                cout << "YES\n";
            else {
                sort(dif.begin(), dif.end());
                int cur = 0;
                fl = false;
                for (int i = 0; i + 1 < dif.size(); ++i) {
                    cur += dif[i].second;
                    if (dif[i].first < dif[i + 1].first && cur == tot)
                        fl = true;
                }
                cout << (fl ? "YES\n" : "NO\n");
            }
        }
    }

    return 0;
}