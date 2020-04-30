using namespace std;
const int N = 3e5 + 10 , M = 200;
int n , a[N];
int vis[N] , cnt[N][220] , pos[N] , far[N] , last[N] , pre[N] ;
int st[N] , f[N];

signed main()
{
	int t;
	cin >> t;
	while(t --)
	{
		int ans = 1;
		cin >> n;
		rep(i , 1 , n) cin >> a[i];
		rep(i , 2 , M) pos[i] = cnt[0][i] = 0;
		rep(i , 1 , n)
		{
			rep(j , 1 , M) cnt[i][j] = cnt[i - 1][j];
			cnt[i][a[i]] ++ ;
		}
		rep(i , 1 , n) pre[i] = pos[a[i]] , pos[a[i]] = i;
		rep(i , 1 , M) pos[i] = far[i] = 0;
		per(i , n , 1) if(!pos[a[i]]) far[a[i]] = i , pos[a[i]] = i;
		rep(i , 1 , M) vis[i] = 0;
		rep(i , 1 , n)
		{
			if(!vis[a[i]]) f[i] = far[a[i]] , st[i]=1 , vis[a[i]] = 1;
			else f[i] = pre[f[last[a[i]]]] , st[i] = st[last[a[i]]] + 1;
			last[a[i]] = i;
			if(i < f[i])
			{
				int l = i + 1 , r = f[i] - 1 , ma = 0;
				rep(j , 1 , M) ma = max(ma , cnt[r][j] - cnt[l - 1][j]);
				ans = max(ans , (st[i] << 1) + ma);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <random>
#include <cmath>
#include <chrono>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
using LL = long long;
#define eps 1e-8
#define fi first
#define se second
#define eb emplace_back
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; cin>>___T; for(int __CS=1;__CS<=___T;__CS++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
int rnd(int x) { return mrand() % x;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 1e6+10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9+7;
void add(int &a,int b) {a+=b; if(a>=mod) a-=mod;}
void dec(int &a,int b) {a-=b; if(a<0) a+=mod;}
int main()
{
	
	
}