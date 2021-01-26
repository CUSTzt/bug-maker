// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int a[N], dp[N], l[N], r[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[1] = 1;
    for(int i= 2; i <= n; i++){
        if(a[i] > a[i-1]) dp[i] = dp[i-1] + 1;
        else dp[i] = 1;
    }
    r[n] = n;
    for(int i = n-1; i >= 1; i--){
        if(a[i] < a[i+1]) r[i] = r[i+1];
        else r[i] = i;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int tp = dp[i-1] + 1;
        if(a[i+1] >= a[i-1] + 2){
            ans = max(ans , tp + r[i+1] - i);
        }else {
            ans = max({ans, tp, r[i+1] - i + 1});
        }
    }
    cout << ans << endl;
    return 0;
}