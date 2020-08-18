#include<bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt","w",stdout);
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

const int N = 2e7+10;
const int p = 1e9+7;
 
int s[N],sv[N],inv[N],a[N],ans[N];
 
ll fpow(ll a, ll k) { ll b = 1; for (; k; k>>=1,a=a*a%p) if (k&1) b=b*a%p; return b; }
 
void pre(int n){
    s[0] = 1;
    for (int i = 1; i <= n; ++i) s[i] = 1LL*s[i - 1] * a[i] % p;
    sv[n] = fpow(s[n], p - 2);
    for (int i = n; i >= 1; --i) sv[i - 1] = 1LL*sv[i] * a[i] % p;
    for (int i = 1; i <= n; ++i) inv[i] = 1LL*sv[i] * s[i - 1] % p;
 
    ll pre=1,fenzi;
    for(int i = 1; i < N; i++){
        fenzi = (a[i] - 1 + p) % p;
        pre = 1ll *  fenzi * inv[i] % p * pre % p;
        ans[i] = ans[i-1] ^ pre;
    }
 
}
int main(){
//    IN;
    IOS;
    a[0]=1;
    for(int i=1;i<N;i++)a[i]=1LL*a[i-1]*2%p;
    pre(N-2);
    int _;cin>>_;
    while(_--){
        int n;cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}