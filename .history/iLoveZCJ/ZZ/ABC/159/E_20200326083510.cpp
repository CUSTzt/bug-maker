// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

// bitmask dp,bf
const int N = 1e3 + 100;
int a[15][N],sum[15][N], n, m, k, b[15];
char s[15][N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> s[i][j];
            a[i][j] = s[i][j] - '0';
            sum[i][j] = sum[i-1][j]+sum[i][j-1]
        }
    }
    return 0;
}