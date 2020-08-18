// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int mod = 998244353, Erica = 998244353;
const int maxn = 1e8 + 10;
ll add(ll a, ll b) {
    a += b;
    return a > mod ? a - mod : a;
}
ll dec(ll a, ll b) {
    a -= b;
    return a < 0 ? a + mod : a;
}
ll mul(ll x, ll y) {
    x *= y;
    return x > mod ? x % mod : x;
}
int inv[maxn], p[30], cnt, tmp, ans, n;
void pre() {
    inv[1] = 1;
    for (int i = 2; i < maxn; i++) {
        inv[i] = 1ll * (Erica - Erica / i) * inv[Erica % i] % Erica;
    }
    for (int i = 2; i < maxn; i++) inv[i] = add(inv[i], inv[i - 1]);
}
void dfs(int x, int d, int u) {
    if (x > cnt) {
        ans = add(ans, mul(mul(u, dec(inv[d], inv[d - 1])), inv[n / d]));
        return;
    }
    dfs(x + 1, d, u);
    dfs(x + 1, d * p[x], mod - u);
    return;
}
void up() {
    ans = 0, cnt = 0;
    cin >> n;
    int tmp = n;
    for (int i = 2; i * i <= tmp; i++)
        if (tmp % i == 0) {
            p[++cnt] = i;
            while (tmp % i == 0) tmp /= i;
        }
    if (tmp > 1) p[++cnt] = tmp;
    if (n != 2)
        dfs(1, 1, 1);
    else
        ans = 0;
    ans = mul(ans, dec(inv[n], inv[n - 1]));
    cout << add(ans, inv[2] - 1) << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pre();
    int pp;
    cin >> pp;
    while (pp--) {
        up();
    }
    return 0;
}