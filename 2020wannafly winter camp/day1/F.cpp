/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-15 15:40:49
# @Description: You build it. You run it
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>

using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
#define int long long
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll inf64 = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9 + 7;
ll A[maxn], B[maxn];
ll a1[maxn], a2[maxn], b1[maxn], b2[maxn];
ll afu = 0, azheng = 0, bfu = 0, bzheng = 0, zeroa = 0, zerob = 0;
ll n, m, k;

bool check(ll x) {
    ll sum = 0;
    if (x <= 0) {
        sum += afu * bfu + azheng * bzheng + zeroa * m + zerob * n - zeroa * zerob;
        if (x == 0)
            return sum >= k;
        if (sum >= k)
            return true;
        x = -x;
        for (int i = 1; i <= afu && bzheng; i++) {
            ll t = upper_bound(b2 + 1, b2 + 1 + bzheng, x / a1[i]) - b2;
            if (b2[t] > x / a1[i] || t > bzheng)
                t--;
            sum += t;
        }
        for (int i = 1; i <= azheng && bfu; i++) {
            ll t = upper_bound(b1 + 1, b1 + 1 + bfu, x / a2[i]) - b1;
            if (b1[t] > x / a2[i] || t > bfu)
                t--;
            sum += t;
        }
        return sum >= k;
    }
    for (int i = 1; i <= afu && bfu; i++) {
        ll val = x / a1[i];
        if (x % a1[i])
            val++;
        int t = lower_bound(b1 + 1, b1 + 1 + bfu, val) - b1;
        sum += bfu - t + 1;
    }
    for (int i = 1; i <= azheng && bzheng; i++) {
        ll val = x / a2[i];
        if (x % a2[i])
            val++;
        int t = lower_bound(b2 + 1, b2 + 1 + bzheng, val) - b2;
        sum += bzheng - t + 1;
    }
    return sum >= k;
}

int32_t main() {
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &A[i]);
    for (int i = 1; i <= m; i++)
        scanf("%lld", &B[i]);
    for (int i = 1; i <= n; i++) {
        if (A[i] < 0)
            a1[++afu] = -A[i];
        else if (A[i] > 0)
            a2[++azheng] = A[i];
        else
            zeroa++;
    }
    for (int i = 1; i <= m; i++) {
        if (B[i] < 0)
            b1[++bfu] = -B[i];
        else if (B[i] > 0)
            b2[++bzheng] = B[i];
        else
            zerob++;
    }
    sort(a1 + 1, a1 + 1 + afu);
    sort(a2 + 1, a2 + 1 + azheng);
    sort(b1 + 1, b1 + 1 + bfu);
    sort(b2 + 1, b2 + 1 + bzheng);
    ll l = -inf64, r = inf64, ans = 0;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("%lld\n", l - 1);
    return 0;
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
