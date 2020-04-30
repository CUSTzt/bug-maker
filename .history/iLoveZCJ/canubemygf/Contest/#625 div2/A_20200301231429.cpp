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
#define int long long 
#define eps 1e-8
#define fi first
#define se second
#define eb emplace_back
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; scanf("%d", &___T); for(int __CS=1;__CS<=___T;__CS++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
int rnd(int x) { return mrand() % x;}
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 1e6+10;
constexpr int MAXN = 1e6+10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9+7;
struct Edge
{
	ll v,nxt,cost;
}e[MAXN];
ll cnt=0,last[MAXN];
void adde(ll u,ll v,ll cost)
{
	e[++cnt].v=v;
    e[cnt].cost =cost;
	e[cnt].nxt=last[u],last[u]=cnt;
}
 
ll dis[MAXN],f[MAXN];
std::queue<int >q;

int  a[MAXN],n,m;
int mn,mx;
void bfs(ll s)
{
	dis[s]=1;f[s]=1;
	q.push(s);
	while(!q.empty())
	{
		ll u=q.front();q.pop();
		for(ll i=last[u];i;i=e[i].nxt)
		{
			ll v=e[i].v;
			if(!dis[v])
			{
				dis[v]=dis[u]+1;q.push(v);
			}
			if(dis[v]==dis[u]+1)++f[v];
		}
	}
}
int32_t main()
{
	cin >> n >>m;
	for(ll i=1;i<=m;++i)
	{
        int u , v;
		cin >> u >> v;
		adde(v,u,1);
	}
    int p;
	cin >> p;
	for(ll i=1;i<=p;++i)cin >> a[i];
    int zcj = a[p];
	bfs(zcj);
	for(ll i=2;i<=p;++i)
	{
		if(dis[a[i]]+1==dis[a[i-1]]){
            if(f[a[i-1]]>1)mx+=1;
            }
		else
		{
            mn+=1;
            mx+=1;
			
		}
	}
	cout << mn <<' ' <<mx;
	return 0;
}