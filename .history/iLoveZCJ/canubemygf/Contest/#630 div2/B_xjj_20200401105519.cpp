// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
int color[N], a[N];
void up() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        color[i] = 0;
    }
    int cc = n, p = 2, m = 0;
    while (cc > 0) {
        int ks = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] % p == 0 && color[i] == 0) ks++;
        }
        
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tp;
    cin >> tp;
    while (tp--) {
        up();
    }
    return 0;
}