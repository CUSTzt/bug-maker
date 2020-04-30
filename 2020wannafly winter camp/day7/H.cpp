#include<bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define IOS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define int size_t
using namespace __gnu_pbds;
template <class T>
struct rbtree: tree<T,null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>{};
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define IN freopen("in.txt", "r", stdin);
#define RI register int
#define endl '\n'
#define pb push_back
#define lowb lower_bound
#define eb emplace_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define mem0(a) memset((a), 0, sizeof(a))
#define mem(a, b) memset((a), (b), sizeof(a))
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int inf = 0x3f3f3f3f;
const int P=998244353;
int a[550][550],b[550][550];


ll det(int n){
    ll ans=1;bool flag=1;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=(a[i][j]+P)%P;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++)while(a[j][i]){
            ll t=a[i][i]/a[j][i];
            for(int k=i;k<=n;k++)a[i][k]=(a[i][k]+P-t*a[j][k]%P)%P;
            for(int k=i;k<=n;k++)swap(a[i][k],a[j][k]);
            flag^=1;
        }
        ans=ans*a[i][i]%P;
        if(!ans)return 0;
    }
    if(!flag)ans=(P-ans);
    return ans;
}

int32_t main(){
    IOS;
    //IN;
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>a[i][j],b[i][j]=a[i][j];
    while(q--){
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=b[i][j];
        int x,y,z;cin>>x>>y>>z;
        a[x][y]=z;
        b[x][y]=z;
        cout<<det(n)<<endl;
    }
    return 0;
}