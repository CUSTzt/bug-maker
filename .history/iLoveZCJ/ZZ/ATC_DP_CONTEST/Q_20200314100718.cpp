// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
ll dp[N], n , h[N],a[N],t[N];
struct BIT{
    #define lowbit(x) x&(-x)
    void update(int x, ll y ){
        for(;x<=n;x+=lowbit(x)){
            t[x] = max(t[x],y);
        }
    }
    ll query(int x){
        ll res= 0;
        for(;x;x-=lowbit(x)){
            res=max(res,t[x]);
        }
    }
}bit;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i<= n; i++){
        dp[i] = quer
    }
    return 0;
}