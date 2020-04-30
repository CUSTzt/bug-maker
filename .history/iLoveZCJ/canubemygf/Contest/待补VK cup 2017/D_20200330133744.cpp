// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2020;
const int inf = 0x3f3f3f3f;
ll a[N][N], ans[N], n, k, dis[N], d = ;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            cin >> k;
            a[i][j] = a[j][i] = k;
            d = min(d,k);
        }
    }
    return 0;
}