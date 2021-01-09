#include <cstdio>
typedef long long ll;
ll cal(ll n) {
    ll i, j;
    ll ans = 0;
    for (i = 1; i <= n; i = j + 1) {
        j = n / (n / i);
        ans += (i + j) * (j - i + 1) * (n / i);
    }
    return ans;
}
int main() {
    ll a, b;
    scanf("%lld%lld", &a, &b);
    printf("%lld", (cal(b) - cal(a - 1)) / 2);
}