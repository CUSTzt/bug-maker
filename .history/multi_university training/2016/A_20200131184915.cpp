#include<bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define IOS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
struct rbtree: tree<T,null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>{};
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define IN freopen("in.txt", "r", stdin);
#define RI register int
//#define endl '\n'
#define pb push_back
#define lowb lower_bound
#define eb emplace_back
#define fi first
#define se second
#define int long long
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

const int N = 1e6+10;
int n,m;
const int MOD=1e9+7;
ll fpow(ll a, ll k) { ll b = 1; for (; k; k>>=1,a=a*a%MOD) if (k&1) b=b*a%MOD; return b; }

int32_t main(){
    IOS;
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        if(m==1)cout<<n+1<<endl;
        else cout<<1*(1-fpow(m,n+1))%MOD*fpow(1-m,MOD-2)%MOD<<endl;
    }
    return 0;
}