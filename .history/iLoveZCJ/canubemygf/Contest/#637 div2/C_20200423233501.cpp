#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
typedef double db;
const ll mod = 998244353;
ll powmod(ll a, ll b) {
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 2e5 + 50;
int n, k;
int T;
int a[N];
int pre[N];
int ans = -0x3f, id, p;
void in() {
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
}
void out() { cout << ans + 1 << " " << id << '\n'; }
int main() {
    int _;
    for (cin >> _; _; --_) {
        int ccnt = 0;
        ++ccnt;
        memset(pre, 0, sizeof pre);
        ++ccnt;
        in();
        for (int i = 3; i <= n; i++) {
            if (a[i - 1] > a[i - 2] && a[i - 1] > a[i])
                pre[i] = pre[i - 1] + 1;
            else
                pre[i] = pre[i - 1];
            ++ccnt;
        }
        ans = -0x3f, id, p;
        ++ccnt;
        int u = 887;
        for (int i = 1; i + k - 1 <= n; i++) {
            int j = i + k - 1;
            ++ccnt;
            if (i >= 3 && a[i - 1] > a[i] && a[i - 1] > a[i - 2])
                p = pre[j] - pre[i - 1] - 1;
            else if (i >= 2 && a[i] > a[i - 1] && a[i] > a[i + 1])
                p = pre[j] - pre[i - 1] - 1;
            else
                p = pre[j] - pre[i - 1];
            if (ans < p) {
                ans = p;
                ++ccnt;
                id = i;
                ++ccnt;
            }
        }
        out();
    }
    return 0;
}
