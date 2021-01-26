#include<stdio.h>
#include<iostream>
#include<sstream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<bitset>
#include<map>
#include<stack>
#include<unordered_set>
#include<unordered_map>
//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
/* --------------- fast io --------------- */ // from dysyn1314	
namespace Fread {
const int SIZE = 1 << 21;
char buf[SIZE], *S, *T;
inline char getchar() {
    if (S == T) {
        T = (S = buf) + fread(buf, 1, SIZE, stdin);
        if (S == T) return '\n';
    }
    return *S++;
}
} // namespace Fread
namespace Fwrite {
const int SIZE = 1 << 21;
char buf[SIZE], *S = buf, *T = buf + SIZE;
inline void flush() {
    fwrite(buf, 1, S - buf, stdout);
    S = buf;
}
inline void putchar(char c) {
    *S++ = c;
    if (S == T) flush();
}
struct NTR {
    ~ NTR() { flush(); }
} ztr;
} // namespace Fwrite
// #ifdef ONLINE_JUDGE
#define getchar Fread :: getchar
#define putchar Fwrite :: putchar
// #endif
namespace Fastio {
struct Reader {
    template<typename T>
    Reader& operator >> (T& x) {
        char c = getchar();
        T f = 1;
        while (c < '0' || c > '9') {
            if (c == '-') f = -1;
            c = getchar();
        }
        x = 0;
        while (c >= '0' && c <= '9') {
            x = x * 10 + (c - '0');
            c = getchar();
        }
        x *= f;
        return *this;
    }
    Reader& operator >> (char& c) {
        c = getchar();
        while (c == '\n' || c == ' ') c = getchar();
        return *this;
    }
    Reader& operator >> (char* str) {
        int len = 0;
        char c = getchar();
        while (c == '\n' || c == ' ') c = getchar();
        while (c != '\n' && c != ' ') {
            str[len++] = c;
            c = getchar();
        }
        str[len] = '\0';
        return *this;
    }
    Reader(){}
} cin;
const char endl = '\n';
struct Writer {
    template<typename T>
    Writer& operator << (T x) {
        if (x == 0) { putchar('0'); return *this; }
        if (x < 0) { putchar('-'); x = -x; }
        static int sta[45];
        int top = 0;
        while (x) { sta[++top] = x % 10; x /= 10; }
        while (top) { putchar(sta[top] + '0'); --top; }
        return *this;
    }
    Writer& operator << (char c) {
        putchar(c);
        return *this;
    }
    Writer& operator << (char* str) {
        int cur = 0;
        while (str[cur]) putchar(str[cur++]);
        return *this;
    }
    Writer& operator << (const char* str) {
        int cur = 0;
        while (str[cur]) putchar(str[cur++]);
        return *this;
    }
    Writer(){}
} cout;
} // namespace Fastio
#define cin Fastio :: cin
#define cout Fastio :: cout
// #define endl Fastio :: endl
/* --------------- fast io --------------- */ // end

#define fr freopen("in.txt","r",stdin);
#define fw freopen("out.txt","w",stdout);
#define pb push_back
#define fi first
#define se second
#define mst0(d) memset(d,0,sizeof d);
#define mstinf(d) memset(d,0x3f,sizeof d);
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define dbg(x) cout << #x << " = "<< (x) << endl
#define dbg2(x1,x2) cout << #x1 << " = " << x1 << "  " << #x2 << " = " << x2 << endl
#define dbg3(x1,x2,x3) cout<< #x1 << " = " << x1 << "  " << #x2 << " = " << x2 << "  " << #x3 << " = " << x3 <<endl
using namespace std;
typedef long long ll;
const int inf=10000007;
const ll mod=1e9+7;
const int N=2e6+5,M=2e6+5;
int n,k;
// int head[N<<1],ver[M<<1],edge[M<<1],nex[M<<1],tot;
bool vis[N],flag[1000006];
int maxp[N],siz[N],S,rt,dis[N];
int rem[N],p[N],dep[N],cnt,minbs[1000006],bs[N],ans=999999;
// inline void add(int x,int y,int z)
// {
//     ver[++tot]=y;edge[tot]=z;nex[tot]=head[x];head[x]=tot;
// }
// const int N = 3e5 + 10;
struct Edge {
    int nxt, to, w;
} edge[N << 1];
int head[N], tot;
void add_edge(int u, int v, int w) {
    edge[++tot].nxt = head[u];
    edge[tot].to = v;
    edge[tot].w = w;
    head[u] = tot;
}

void findroot(int x,int fa)
{
    maxp[x]=0,siz[x]=1;
    for(int i=head[x];i;i=edge[i].nxt){
        int y=edge[i].to;
        if(y==fa||vis[y])continue;
        findroot(y,x);
        maxp[x]=max(maxp[x],siz[y]);
        siz[x]+=siz[y];
    }
    maxp[x]=max(maxp[x],S-siz[x]);
    if(maxp[x]<maxp[rt])rt=x;
}
void getdis(int x,int fa)
{
    if(dis[x]>k)return;
    rem[++rem[0]]=dis[x];
    bs[++bs[0]]=dep[x];
    for(int i=head[x];i;i=edge[i].nxt){
        int y=edge[i].to;
        if(y==fa||vis[y])continue;
        dis[y]=dis[x]+edge[i].w;
        dep[y]=dep[x]+1;
        getdis(y,x);
    }
}
queue<int>q;
void calc(int x)
{
    flag[0]=1;
    minbs[0]=0;
    for(int i=head[x];i;i=edge[i].nxt){
        int y=edge[i].to;
        if(vis[y])continue;
        rem[0]=bs[0]=0;
        dis[y]=edge[i].w;
        dep[y]=1;
        getdis(y,-1);
        for(int j=1;j<=rem[0];j++){
            if(k>=rem[j]&&flag[k-rem[j]])
            ans=min(ans,bs[j]+minbs[k-rem[j]]);
        }
        for(int j=1;j<=rem[0];j++){
            q.push(rem[j]);
            flag[rem[j]]=1;
            minbs[rem[j]]=min(minbs[rem[j]],bs[j]);
        }
    }
    while(q.size()){
        int fq=q.front();
        flag[fq]=0;
        minbs[fq]=inf;
        q.pop();
    }
}
void solve(int x)
{
    vis[x]=1;
    calc(x);
    for(int i=head[x];i;i=edge[i].nxt){
        int y=edge[i].to;
        if(vis[y])continue;
        maxp[rt=0]=inf;
        S=siz[y];
        findroot(y,-1);
        findroot(y,-1);
        solve(y);
    }
}
int main()
{
    memset(minbs,10,sizeof minbs);
    // scanf("%d%d",&n,&k);
    cin >> n >> k;
    for(int i=1;i<n;i++){
        int x,y,z;
        // scanf("%d%d%d",&x,&y,&z);
        cin >> x >> y >> z;
        add_edge(x,y,z);
        add_edge(y,x,z);
    }
    maxp[rt=0]=inf;
    S=n;
    findroot(rt,-1);
    findroot(rt,-1);
    solve(rt);
    if(ans==999999)ans=-1;
    cout<<ans<<'\n';
    return 0;
}
