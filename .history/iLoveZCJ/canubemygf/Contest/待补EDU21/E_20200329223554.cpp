// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
int n , m;
ll dp[N];
struct node {
    int w, c;
    double div;
}a[N];
int cmp(const node a ,const node b){
    return a.div > b.div;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i<= n; i++){
        cin >> a[i].w >> a[i].c;
        a[i].div = 1.0*a[i].c / a[i].w;
    }
    sort(a+1, a+n+1);
    ll ans = 0;
    memset(dp, 0xcf, sizeof dp);
    int zz = 0;
    for(int i = 1; i <= n; i++){
        zz += a[i].w;
        if(zz > m) zz = m;
        int zb = max(a[i].w,zz-6);
        for(int j = zz; j >= zb; j--){
            dp[j] = max(dp[j] , dp[j-a[i].])
        }
    }
    return 0;
}