// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;

int n, l, r;
int s[N];
int calc(int x) {
    if (x > s[n - 1]) return 1;
    int pos = lower_bound(s+1, s+n,x)-s;
    int b = x - s[pos-1];
    if(b & 1)return pos;
    else return b/2+pos;
}
void up() {
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + (2 * (n - i));
    }
    for(int i = l ;i <= r; i++){
        cout << calc(i) <<' ';
    }cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--) up();
    return 0;
}