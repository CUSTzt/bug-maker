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

int n,p;

int ck(VI a){
    map<ll,ll> mp;
    ll c1=0,sum=0;
    for(int i=1;i<=n;i++){
        if(a[i]%p==0){
            c1++;
            sum=0;
            mp.clear();
        }else{
            sum=(sum+a[i]%p)%p;
            if(mp[sum] || !sum){
                sum=0;
                c1++;
                mp.clear();
            }else mp[sum]++;
        }
    }
    return c1;
}
void solve(){
    cin>>n>>p;
    VI res;
    res.pb(-1);
    for(int i=1,x;i<=n;i++){
        cin>>x;
        res.pb(x);
    }
    res.pb(-1);
    int ans=0;
    ans=max(ans,ck(res));
    reverse(all(res));
    ans=max(ans,ck(res));
    cout<<ans<<endl;
}
int main(){
//    IN;
    IOS;
    int _;cin>>_;
    while(_--)solve();
    return 0;
}