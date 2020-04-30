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
#define int long long 
#define se second
#define eb emplace_back
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORd(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define caSET int ___T; cin>>___T; for(int __cS=1;__cS<=___T;__cS++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
int rnd(int x) { return mrand() % x;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
LL bin(LL x, LL n, LL MOd) {LL ret = MOd != 1;for (x %= MOd; n; n >>= 1, x = x * x % MOd)if (n & 1) ret = ret * x % MOd;return ret;}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 1e6+10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9+7;
void add(int &a,int b) {a+=b; if(a>=mod) a-=mod;}
void dec(int &a,int b) {a-=b; if(a<0) a+=mod;}
int father[maxn];
int Find(int x)//并查集查找父节点
{
    if(father[x]==x) return father[x];
    return father[x]=Find(father[x]);
}
void Union(int x,int y)//合并
{
    int fa=Find(x);
    int fb=Find(y);
    if(fa!=fb) father[fb]=fa;
}
char tp[maxn];
int na , nb  , nc , nd , m , x , y, ans,cnt[maxn];
void dfs(int a , int b , int c , int d , int now){
    if(13 == now){
        for(int i = 1; i <= 12; i++){
            if(tp[i] != tp[Find(i)])return ;
        }
        ans++;
        return ;
    }
    if (a) {
        tp[now] = 'a';
        dfs(a - 1, b, c, d, now + 1);
        tp[now] = 'X';
    }
    if (b) {
        tp[now] = 'b';
        dfs(a, b - 1, c, d, now + 1);
        tp[now] = 'X';
    }
    if (c) {
        tp[now] = 'c';
        dfs(a, b, c - 1, d, now + 1);
        tp[now] = 'X';
    }
    if (d) {
        tp[now] = 'd';
        dfs(a, b, c, d - 1, now + 1);
        tp[now] = 'X';
    }
}
int32_t main()
{
    close;
    cin >> na >> nb >> nc >> nd >> m;
    for(int i = 1; i <= 20; i++){
        father[i] = i;
    }
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        Union(x , y);
    }
    for(int i = 1; i <= 12; i++)Find(i);
    for(int i = 1; i <= 12; i++){
        cnt[father[i]]++;
        tp[i] = 'X';
    }
    dfs(na , nb , nc , nd ,  1);
    cout << ans << endl;   
}