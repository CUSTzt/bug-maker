#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef long long int ll;
typedef vector<pair<int, int> > vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long int> vll;
typedef pair<int, int> pii;

const ll INF = 1e18;
const int inf = 1e9;
const int MOD = 1e9 + 7;
const int nax = 1000000 + 10;

int n, arr[nax];
vii v;
int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num, tim;
        cin >> num >> tim;
        v.pb({tim, num});
    }
    ll cnt = 1;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    ll ans = 0;
    for (auto x : v) {
        if (cnt <= 0) break;
        cnt--;
        ans += x.ss;
        cnt += x.ff;
    }
    cout << ans << endl;
    return 0;
}