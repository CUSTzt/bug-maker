//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
using LL = long long;
#define eps 1e-8
#define fi first
#define se second
#define eb emplace_back
#define SZ(a) int(a.size())
#define ALL(x) (x).begin(), (x).end()
#define trav(a, x) for (auto &a : x)
#define LOG(FMT...) fprintf(stderr, FMT)
#define close \
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c)         \
    (sort(c.begin(), c.end()), \
     c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
#define CASET    \
    int ___T;    \
    cin >> ___T; \
    for (int __CS = 1; __CS <= ___T; __CS++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 3000 + 10;
constexpr int mod = 1e9 + 7;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260811, P_2 = 999998639;
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void dec(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m, t, vis[maxn][maxn];
char s[maxn][maxn];
struct node {
    /* data */
    int x, y, d;
    char pd;
};

int chk(int x, int y, char c) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (s[xx][yy] == c) return 1;
    }
    return 0;
}
int check(int x, int y) {
    if (x >= 1 && x <= n && y >= 1 && y <= m && vis[x][y] == -1) return 1;
    return 0;
}
int len;
int main() {
    close;
    cin >> n >> m >> t;
    memset(vis, 0xcf, sizeof vis);
    for (int i = 1; i <= n; i++) {
        cin >> s[i] + 1;
        len = strlen(s[i] + 1);
    }
    queue<node> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (chk(i, j, s[i][j]) ) {
                vis[i][j] = 0;
                q.push({i, j, 0});
            }
        }
    }
    cout << "end1"<<endl;;
    while (!q.empty()) {
        node sta = q.front();
        q.pop();
        cout << "sta.x == " << sta.x << "  sta.y == " << sta.y << endl;
        for (int i = 0; i < 4; i++) {
            int xx = sta.x + dx[i], yy = sta.y + dy[i];
            if (check(xx, yy)) {
                if(s[xx][yy]==s[sta.x][sta.y]){
                q.push({xx,yy,sta.d});
                vis[xx][yy] = sta.d;
            }else {
                q.push({xx,yy,sta.d+1});
                vis[xx][yy] = sta.d+1;
            }
        }
    }
    cout << "bfs end"<<endl;
    for (int i = 0; i < t; i++) {
        int a, b , c;
        cin >> a >> b >> c;
        int ans = s[a][b] - '0';
        if(vis[a][b] >= 0 && c > vis[a][b] && (c - vis[a][b]) & 1) ans ^= 1;
        cout << ans <<endl ;
    }
}