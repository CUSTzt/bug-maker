#include<bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define IN freopen("in.txt", "r", stdin);
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

void solve(){
    int n;cin>>n;
    if(n==1)cout<<26<<endl;
    else if(n==2)cout<<676<<endl;
    else if(n==3)cout<<17576<<endl;
    else cout<<15600<<endl;
}
int main(){
    IOS;
    int _;cin>>_;
    while(_--)solve();
    return 0;
}