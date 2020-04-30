// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
ll n, k, x[30];
bool isprime(ll x) {
    ll m = sqrt(x);
    for (int i = 2; i <= m; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 0;  i < n; i++){
        cin >> x[i];
    }
    int cnt = 0;
    for(int i = 0; i < 1<<n; i++){
        if(__builtin_popcount(i) != k)continue;
        ll tmp = 0;

        if(isprime(tmp))
    }
    return 0;
}