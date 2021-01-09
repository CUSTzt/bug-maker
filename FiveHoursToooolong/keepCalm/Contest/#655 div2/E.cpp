// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

void umax(int &a , int b){
    if( a < b) a = b;
}
// others
const int N = 10+100;
int a[N][N], dp[N][N], n , m;
int solve(int l , int r){
    if( l > r) return 0;
    int &ans = dp[l][r];
    if(ans != -1) return ans;
    ans = 0;
    set<int> s;
    for(int i = 1; i <= n; i++) s.insert(a[i][l-1]), s.insert(a[i][r+1]);
    for(int j = l ; j <= r; j++){
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(s.count(a[i][j]) == 0) cnt++;
        }
        umax(ans , cnt * cnt + solve(l, j-1) + solve(j+1 , r));
    }
    return ans;
}
int zz;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int k; cin >> k;
        while(k--){
            ++zz;
            int l , r ;
            cin >> l >> r;
            for(int j = l; j <= r; j++) a[i][j] = zz;
        }
    }
    memset(dp , 0xff , sizeof dp);
    cout << solve(1 , m) << endl;
    return 0;
}