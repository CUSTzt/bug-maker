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
 
const int N = 220;
int a[N][N];
 
void solve(){
    int n,m;cin>>n>>m;
    double ans=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
    for(int i=1;i<=m;i++){
        ll sum=0;
        for(int j=1;j<=n;j++){
            sum+=a[j][i];
            ans=max(ans,(1.*sum)/a[j][i]);
        }
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}
int main(){
//    IN;
    IOS;
    int _;cin>>_;
    while(_--)solve();
    return 0;
}