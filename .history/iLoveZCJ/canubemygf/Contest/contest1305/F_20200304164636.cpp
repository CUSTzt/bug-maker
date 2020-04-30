// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
mt19937 RNG(std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n)
{
    return RNG() % n;
}
int n;
ll a[N];
ll solvePrime(ll p)
{
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        ll l = a[i] - a[i] % p;
        if (l != 0)
        {
            res += min(a[i] - 1, l + p - a[i]);
        }
        else
        {
            res += p - a[i];
        }
    }return res;
}
ll solve(ll x)
{
    ll res = n;
    ll m = sqrt(n + 0.5);
    for (ll i = 2; i <= m; i++)
    {
        if (x % i == 0)
        {
            res = min(res, solvePrime(i));
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
        res = min(res, solvePrime(x));
    return res;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    random_shuffle(a, a + n, rnd);
    ll ans = n;
    for (int i = 0; i < min(30, n); i++)
    {
        if (a[i] > 1)
            ans = min(ans, solve(a[i] - 1));
        ans = min(ans, solve(a[i]));
        ans = min(ans, solve(a[i] + 1));
    }
    cout << ans << endl;
    return 0;
}