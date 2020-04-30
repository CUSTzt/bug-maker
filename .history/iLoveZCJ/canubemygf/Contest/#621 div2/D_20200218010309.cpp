#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
using LL = long long;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; scanf("%d", &___T); for(int __CS=1;__CS<=___T;__CS++)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
int n , m , k ;
vector<int >G[maxn];
int a[maxn], vis[maxn], mx[maxn] , ss[maxn];
struct NODE{
    int xx , yy;
    NODE(int xx = 0, int yy = 0):xx(xx),yy(yy){}
}s[maxn];
struct node{
    int d , dd;
    node(int d = 0, int dd= 0):d(d),dd(dd){}
}b[maxn];
bool cmp(node a , node b){
    return a.d < b.d;
}
void update(int loc,int x,int k,int l,int r){
    if(l==r){
        ss[x]=max(ss[x],k);
        return;
    }
    int mid=l + (r-l) / 2;
    if(loc<=mid)update(loc,x*2,k,l,mid);
    else update(loc,x*2+1,k,mid+1,r);
    ss[x]=max(ss[x*2],ss[x*2+1]);
}
int query(int a,int b,int x,int l,int r){
    if(a==l&&b==r)return ss[x];
    int mid=l+r>>1;
    int ls=x<<1,rs=x<<1|1;
    if(b<=mid)return query(a,b,ls,l,mid);
    else if(a>mid)return query(a,b,rs,mid+1,r);
    else return max(query(a,mid,ls,l,mid),query(mid+1,b,rs,mid+1,r));
}
bool check(int x){
    //for(int i=0;i<maxn;i++)ss[i]=-INF;
    for(int i=1;i<=k;i++){
        int l=max(0,x-b[i].d);
        //cout<<l<<' '<<query(l,n,1,0,n)<<' '<<b[i].dd<<endl;
        if(query(l,n,1,0,n)+b[i].dd+1>=x)return 1;
        update(b[i].dd,1,b[i].d,0,n);
    }
    return 0;
}
void bfs() {
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    vis[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        //cout<<' '<<x<<' '<<s[x].d<<endl;
        q.pop();
        for (int i = 0; i < G[x].size(); i++) {
            int &y = G[x][i];
            if (vis[y])continue;
            s[y].xx = s[x].xx + 1;
            q.push(y);
            vis[y] = 1;
        }
    }
    return;
}

void bfs2() {
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    vis[n] = 1;
    q.push(n);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < G[x].size(); i++) {
            int &y = G[x][i];
            if (vis[y])continue;
            s[y].yy = s[x].yy + 1;
            vis[y] = 1;
            q.push(y);
            //vis[y] = 1;
        }
    }
    return;
}
void read(){
    close;
    cin >> n >> m >> k;

}
int main()
{
    
    
}