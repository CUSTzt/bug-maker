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
#define int long long 
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
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9+7;
struct node
{
    int to,w,next;
}edge[maxn];
int head[maxn], cnt;
int dis[maxn], vis[maxn],zz[maxn],n , m , u , v , k , p[maxn], s , t; ;
void init()
{
    memset(head,-1,sizeof(head));
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    cnt = 0;
}
queue<int >q;
void add(int u,int v,int w)
{
    edge[++cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
int  bfs(int s){
    dis[s] = 1;
    zz[s]=1;
    q.push(s);
    while(q.empty()){
        int u = q.front();
        for(int i = head[u];i!=-1;i=edge[i].next){
            int v = edge[i].to;
            if(!dis[v])
			{
				dis[v]=dis[u]+1;q.push(v);
			}
			if(dis[v]==dis[u]+1)zz[v]+=1;
        }
        q.pop();
    }
    return 0;
}
int mn , mx;
int32_t main()
{
    cin >> n >> m;
    for(int i = 0; i <m; i++){
        cin >> u >> v;
        add(v , u , 1);
    }
    cin >> k;
    for(int i = 1; i <= k;i++){
        cin >> zz[i];
    }
    int zcj = p[k];
    bfs(zcj);
    for(int i = 2; i <= k; i++){
        if(dis[p[i-1]]==dis[p[i]]+1){
            if(zz[p[i-1]>=2])mx++;
        }else {
            mx++;
            mn++;
        }
    }
    cout << mn <<' ' <<mx ;
    
}