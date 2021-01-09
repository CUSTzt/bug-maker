// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3000;
const int mod = 1e9+9;
ll num[N][N], dp[N][N];
template<class T>inline void add(T &x, T y) {x += y; if(x >= mod) x -= mod;}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll k , b;
    cin >> k >> b;
    ll tp = 1;
    num[0][0] = 1;
    for(int i = 1; i <= b; i++){
        for(int j = 0; j < k; j++){
            add(num[i][j] , num[i-1][j]);
            add(num[i][(j+tp)%k],num[i-1][j]);
        }
        tp = (tp << 1) % k;
    }
    tp = 1;
    for(int i = 1; i <= b; i++){
        for(int j = 0; j < k; j++){
            add(dp[i][j] , dp[i-1][j]);
            add(dp[i][(j+tp)%k],(dp[i-1][j] + num[i-1][j])%mod);
        }
        tp = (tp << 1) % k;
    }
    cout << dp[b][0] % mod << endl;
    return 0;
}