// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 100, M = 202;

int a[N], kk[N][M];
void up() {
    int n, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 1; j <= M; j++) {
            kk[i][j] = kk[i - 1][j];
        }
        kk[i][a[i]]++;
        ans = max(ans, kk[i][a[i]]);
    }
    for (int i = 1; i <= n; i++) {
        int t = a[i];
        int ks = kk[i][t];
        int l = 1, r = n;
        while (r > l) {
            int mid = (l + r) >> 1;
            if (kk[n][t] - kk[mid - 1][t] >= ks)
                l = mid;
            else
                r = mid;
        }
        int pos = 0;
        if(kk[n][t] - kk[r-1][t]>=ks){}
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