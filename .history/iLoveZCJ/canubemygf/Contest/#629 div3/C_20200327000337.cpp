// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}
const int N = 2e5 + 10;
int a[N] , num[N] , cnt[N];
int pre[N] , suf[N] , pcnt[N] , scnt[N];
int ans = 1e18;
signed main()
{
    int n , k , m = 0;
    cin >> n >> k;
    rep(i , 1 , n) cin >> a[i]; 
    sort(a + 1 , a + 1 + n); 
    int S = 0;
    rep(i , 1 , n)
    {
        S ++;
        if(a[i] != a[i + 1])
        {
            m ++;
            num[m] = a[i] , cnt[m] = S;
            S = 0;
        }
    }
    rep(i , 2 , m)
    {
        pre[i] = pre[i - 1] + pcnt[i - 1] * (num[i] - num[i - 1]) + cnt[i - 1] * (num[i] - num[i - 1] - 1);
        pcnt[i] = pcnt[i - 1] + cnt[i - 1];
    }
    per(i , m - 1 , 1)
    {
        suf[i] = suf[i + 1] + scnt[i + 1] * (num[i + 1] - num[i]) + cnt[i + 1] * (num[i + 1] - num[i] - 1);
        scnt[i] = scnt[i + 1] + cnt[i + 1];
    }
    rep(i , 1 , m) 
    {
        int res = k - cnt[i];  
        if(res <= 0)
        {
            puts("0");
            return 0;
        }
        if(i > 1 && i < m)
            ans = min(ans , pre[i] + suf[i] + res);

        if(i > 1 && pcnt[i] >= res)
            ans = min(ans , pre[i] + res);

        if(i < m && scnt[i] >= res)
            ans = min(ans , suf[i] + res);
    }
    cout << ans;
    return 0;
}