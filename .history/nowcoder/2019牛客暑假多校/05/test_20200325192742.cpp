#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 3;
// namespace Hash {
// const int maxn = 1e6 + 3;
// int cnt, head[maxn], nxt[maxn];
// ll val[maxn], pos[maxn];
// void init() {
//     cnt = 0;
//     memset(head, -1, sizeof(head));
// }
// void insert(ll x, ll y) {
//     ll tx = x % maxn;
//     val[cnt] = x, pos[cnt] = y;
//     nxt[cnt] = head[tx];
//     head[tx] = cnt++;
// }
// ll get(ll x) {
//     ll tx = x % maxn;
//     for (int i = head[tx]; ~i; i = nxt[i]) {
//         if (val[i] == x) return pos[i];
//     }
//     return -1;
// }
// }  // namespace Hash
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;

gp_hash_table<int, int> mp;
//cc_hash_table<int, int> mp;
// unordered_map<ll, ll> mp;
long long n, x0, a, b, p;
ll mul(ll a, ll b) { return 1ll * a % p * b % p; }
ll fpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}
ll inv(ll x) { return fpow(x, p - 2); }
ll add(ll a, ll b) { return (a % p + b % p + p) % p; }
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll q, v;
        // Hash::init();
        mp.clear();
        scanf("%lld%lld%lld%lld%lld", &n, &x0, &a, &b, &p);
        scanf("%lld", &q);
        ll m = sqrt(p) + 1;
        ll t = fpow(a, m);
        ll s = 1;
        for (int i = 1; i <= m; i++) {
            s = 1ll * s * t % p;
            //ll tp = mp.find(s);//Hash::get(s);
            //if (tp == -1) //Hash::insert(s, i * m);
            if(mp.find(s) )mp.insert()
        }
        while (q--) {
            scanf("%lld", &v);
            //   mp.clear();
            if (a == 0) {
                if (x0 == v)
                    printf("0\n");
                else if (v == b)
                    printf("1\n");
                else
                    printf("-1\n");
                continue;
            }
            if (a == 1) {
                ll ans = ((v - x0 + p) % p) * inv(b) % p;
                if (ans < n)
                    printf("%lld\n", ans);
                else
                    printf("-1\n");
                continue;
            }
            ll y = mul(add(b, mul(v, a - 1)),
                       inv(((mul(a, x0) - x0 + p) % p + b) % p));
            ll ans = p + 1;
            ll s = y;
            if (y == 1) {
                printf("0\n");
                continue;
            }
            for (int i = 0; i < m; i++) {
                ll tp = Hash::get(s);
                if (tp != -1) ans = min(ans, tp - i);
                s = s * a % p;
            }
            if (ans > p || ans >= n)
                printf("-1\n");
            else
                printf("%lld\n", ans);
        }
    }
    return 0;
}