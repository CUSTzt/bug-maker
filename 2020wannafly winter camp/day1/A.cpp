#include<bits/stdc++.h>
using namespace std;
using LL = long long ;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
#define int long long 
typedef long long ll;
const int maxn = 1e6+100;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 998244353;
int inv[maxn];
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
int get_inv(int n , int p){
	return bin(n, p-2, p);
}
struct node {
	int l , r;
}a[maxn];
bool cmp (node A, node B){
	return (A.l + A.r) < (B.l + B.r); 
}
int Case(node A , node B){
	//if(A.r < B.l)return 0;
	int l = max(A.l , B.l);
	if(l > A.r)return 0;
	int r = min(B.r , A.r);
	int ret = (l + r - B.l - B.l) * (r - l + 1) /2 % mod;
	ret = (ret + (A.r - r) * (B.r - B.l + 1) % mod);
	return ret;
}
int t,n;
int32_t main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i].l >> a[i].r;
	}
	sort(a , a+n , cmp);
	for(int i = 0; i < n; i++){
		inv[i] = get_inv(a[i].r - a[i].l+1,mod);
	}
	int ans = 0;
	for (int i = 0;i < n;i++)
		for (int j=i+1;j<n;j++)
			ans=(ans+1ll*inv[i]*inv[j]%mod*Case(a[i],a[j]))%mod;
	cout << ans << endl;
}




