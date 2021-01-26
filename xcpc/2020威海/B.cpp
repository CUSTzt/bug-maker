//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <algorithm>
#include <cassert>
#include <bits/stdc++.h>
#include <functional>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
using LL = long long;
// #define int LL
#define eps 1e-8
#define fi first
#define se second
#define endl '\12'
#define eb emplace_back
#define SZ(a) int32_t(a.size())
#define ALL(x) (x).begin(),(x).end()
#define trav(a,x) for (auto& a: x)
#define LOG(FMT...) fprintf(stderr, FMT)
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr),cout<<fixed<<setprecision(10)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; cin>>___T; for(int __CS=1;__CS<=___T;__CS++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
constexpr int mod = 1e9+7; // 998244353
// mt19937 dlsrand(random_device{}());
// mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
// int rnd(int x) { return mrand() % x;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll ex_gcd(ll a, ll b, ll& x, ll& y){if(!b){x=1;y=0;return a;}ll ret=ex_gcd(b,a%b,y,x);y-=a/b*x;return ret;}
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
int norm(int x) { return x >= mod ? (x - mod) : x; }
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
inline ll get_inv(ll a) { ll x, y; ex_gcd(a, mod, x, y); return norm(x + mod);}
template<class T>inline void umin(T &x, T y) {x = x > y ? y : x;}
template<class T>inline void umax(T &x, T y) {x = x < y ? y : x;}
template<class T>inline void dec(T &x, T y) {x -= y; if(x < 0) x += mod;}
template<class T>inline void add(T &x, T y) {x += y; if(x >= mod) x -= mod;}
const double PI = acos(-1.0);
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base=2333, P_1=19260817, P_2=999998639;
constexpr int maxn = 1e6+1; // remember to calculate. if tle, check maxn first.
constexpr int dx[] = {1 , 0 , -1 , 0};
constexpr int dy[] = {0 , 1 , 0 , -1};
#define vv vector<vi>
int n , m, k , q;
vv s, d[200];
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
// const char endl = '\n';
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

int32_t main()
{
    // freopen("in.txt","r",stdin);
    // close;
    // int n , m , k , q;
    cin >> n >> m >> k >> q;
    s.resize(n+10);
    for(int i = 0; i <= n; i++){
        s[i].resize(m+1);
    }
    for(int i = 0; i < k*4; i++){
        d[i].resize(n+1);
        for(int j = 1; j <= n; j++){
            d[i][j].resize(m+1);
        }
    }
    for(int i = 1, x, y; i <= k; i++){
        cin >> x >> y;
        s[x][y]++;
    }
    vector<pii> v;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i][j] == 1){
                for(int t = 0; t < 4; t++){
                    int xx = i+dx[t], yy = j + dy[t];
                    if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && s[xx][yy] == 0){
                        v.eb(xx,yy);
                    }
                }
            }
        }
    }
    function<void (int , int, vv& )> bfs = [&](int stx , int sty , vv &d){
        queue<pii>q;
        q.push({stx , sty});
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                d[i][j] = -1;
            }
        }
        d[stx][sty] = 0;
        while(not q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int t = 0; t < 4; t++){
                int xx = x + dx[t], yy = y + dy[t];
                if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && s[xx][yy] != 1 && d[xx][yy] == -1){
                    d[xx][yy] = d[x][y] + 1;
                    q.push({xx, yy});
                }
            }
        }
    };
    for(int i = 0; i < SZ(v); i++){
        bfs(v[i].fi , v[i].se, d[i]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            s[i][j] = s[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }
    while(q--){
        int stx , sty , edx , edy;
        cin >> stx >> sty >> edx >> edy;
        int mnx = min(stx, edx), mxx = max(stx, edx ), mny = min(sty , edy ), mxy = max(sty ,edy);
        // cout << mnx << " " << mxx << ' ' << mny << " " << mny << endl;
        int sum = s[mxx][mxy]-s[mnx-1][mxy]-s[mxx][mny-1]+s[mnx-1][mny-1];
        // cout << "sum == " << sum << endl;
        if(!sum){
            cout << abs(edx-stx)+abs(edy-sty) << endl;
        }else{
            int ans = 0x7fffffff;
            for(int i = 0; i < SZ(v); i++){
                // cerr << d[i][stx][sty] << " " << d[i][edx][edy] << endl;
                if(d[i][stx][sty]!=-1 && d[i][edx][edy]!=-1){
                    umin(ans , d[i][stx][sty]+d[i][edx][edy]);
                    // cout << "ans == " << ans << endl;
                }
            }
            cout << (ans == 0x7fffffff ? -1 : ans ) << endl;
        }
    }
    return 0;
}

/*
 5 5 4 7
 2 2
 2 3 
 3 2
3 3
2 1 3 4
1 1 1 1
2 2 2 2
1 1 1 5
2 2 5 5
2 1 2 4
1 1 3 3


2 3 1 1
6
1 1 1 1
0
2 2 2 2
-1
1 1 1 1
4
2 5 2 2
-1
2 2 1 1
5
1 3 1 1
-1
*/