    #include <algorithm>
    #include <cassert>
    #include <chrono>
    #include <cmath>
    #include <cstdio>
    #include <cstring>
    #include <iostream>
    #include <map>
    #include <queue>
    #include <random>
    #include <set>
    #include <stack>
    #include <string>
    #include <vector>
    using namespace std;
    using LL = long long;
    #define eps 1e-8
    #define fi first
    #define se second
    #define eb emplace_back
    #define close \
        std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
    #define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
    #define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
    #define SORT_UNIQUE(c)         \
        (sort(c.begin(), c.end()), \
        c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
    #define CASET    \
        int ___T;    \
        cin >> ___T; \
        for (int __CS = 1; __CS <= ___T; __CS++)
    typedef long long ll;
    typedef vector<int> vi;
    typedef pair<int, int> pii;
    mt19937 dlsrand(random_device{}());
    mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count());
    int rnd(int x) { return mrand() % x; }
    ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
    LL bin(LL x, LL n, LL MOD) {
        LL ret = MOD != 1;
        for (x %= MOD; n; n >>= 1, x = x * x % MOD)
            if (n & 1) ret = ret * x % MOD;
        return ret;
    }
    inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
    const double PI = acos(-1.0);
    constexpr int maxn = 3e6 + 10;
    constexpr int INF = 0x3f3f3f3f;
    constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
    constexpr int mod = 1e9 + 7;
    void add(int &a, int b) {
        a += b;
        if (a >= mod) a -= mod;
    }
    void dec(int &a, int b) {
        a -= b;
        if (a < 0) a += mod;
    }
    vector<int> v[maxn];
    char s[maxn];
    int main() {
        close;
        int n, k;
        cin >> n >> k;
        cin >> (s+1);
        int cnt = 0, sum = 0;
        while (1) {
            int fl = 0;
            cnt++;
            for (int i = 1; i < n; i++) {
                if (s[i] == 'R' && s[i + 1] == 'L') {
                    fl = 1;
                    v[cnt].eb(i);
                }
            }
            for (auto it : v[cnt]) {
                swap(s[it], s[it + 1]);
            }
            sum += v[cnt].size();
            if (!fl) break;
        }
        cnt--;
        if (k < cnt || k > sum) return cout << -1, 0;
        for (int i = 1; i <= cnt; i++) {
            while (!v[i].empty() && k > cnt - i + 1) {
                cout << "1 " << v[i].back() << '\n';
                v[i].pop_back();
                k--;
            }
            if (!v[i].empty()) {
                cout << v[i].size();
                for (auto it : v[i]) {
                    cout << ' ' << it;
                }
                cout << endl;
                k--;
            }
        }
    }