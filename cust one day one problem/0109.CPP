#include<bits/stdc++.h>
 
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
ll f[maxn];
void init(){
    f[1] = 2,f[2] = 4;
    for(int i = 3; i <= 100086;i++){
        f[i] = (f[i-1] + f[i-2]) % mod;
    }
}
int main(){
    ll n , m ;
    init();
    cin >> n >> m ;
    cout << (f[n]+f[m]-2)%mod <<  endl;
    return 0;
}