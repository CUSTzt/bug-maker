#include<bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define IN freopen("in.txt", "r", stdin);
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define fi first
#define int long long
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5+10;

int n,c,t;
int a[N];
bool ck(int tar){
    ll now=1,sum=0;
    for(int i=1;i<=n;i++){
        if((a[i]+t-1)/t>tar) return 0;
        int ss=(sum+a[i]+t-1)/t;
        if(ss>tar){
            if(now==c){
                sum+=a[i];
            }
            else{
                sum=a[i];
                now++;
            }
        }else sum+=a[i];
    }
    return (sum+t-1)/t<=tar;
}

int32_t main(){
    IOS;
    cin>>n>>c>>t;
    for(int i=1;i<=n;i++)cin>>a[i];
    ll l=1,r=inf,ans;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(ck(mid))r=mid-1,ans=mid;
        else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
/*
5 3 4
5 8 3 10 7

3 2 1
1 5 1

3 2 1
1 1 5
*/