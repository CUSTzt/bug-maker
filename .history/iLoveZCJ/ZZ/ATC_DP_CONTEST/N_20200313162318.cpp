// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1100;
ll n, a[N],f[N][N], sum[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n;
    memset(f, 0x3f, sizeof f);
    for(int i = 1; i <= n; i++){
        f[i][i] = 0;
        cin >> a[i];
        sum[i] = sum[i-1]+a[i];
    }
    for(int len = 1; len < n; len++){
        for(int l = 1; l + len <= n; l++){
            int r = l + len;
            for(int k = l; k < r; k++){
                f[l][r] = min(f[l][r] , f[l][k]+f[k+1][r]);
            }
            sum += 
        }
    }
    cout <<f[1][n] <<endl;
    return 0;
}
