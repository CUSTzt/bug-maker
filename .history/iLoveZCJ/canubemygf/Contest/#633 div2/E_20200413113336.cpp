// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
const ll a[] = {0, 2, 3, 1};
void up() {
    ll n;
    cin >> n;
    n--;
    ll k = n / 3;
    ll s = 1;
    while (k >= s) {
        k -= s;
        s *= 4;
    }
    ll a = s + k, b = 2 * s;
    for (int i = 0; (1ll << i) < s; i += 2) {
        b += a[(k >> i) & 3] << i;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--) up();
    return 0;
}