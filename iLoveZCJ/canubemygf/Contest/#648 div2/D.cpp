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
constexpr int maxn = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr int Erica = 998244353;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base = 2333, P_1 = 19260811, P_2 = 999998639;
void umax(int &a, int b) {
    if (a < b) a = b;
}
void umin(int &a, int b) {
    if (a > b) a = b;
}
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void dec(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}

char s[110][110];
int n, m;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int vis[55][55];
bool chk(int x, int y) {
    if (x > n || x < 1 || y > m || y < 1 || s[x][y] == '#') return true;
    return false;
}
int dis[55][55], st[55][55];
void init() {
    memset(dis, 0x3f, sizeof dis);
    memset(st, 0, sizeof st);
    memset(vis, 0, sizeof vis);
}
void solve() {
    init();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] + 1;
    }
    int fl = 1, cn=0;
    vector<pii> good, bad;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'G') {
                cn++;
                good.push_back({i, j});
            }
            if (s[i][j] == 'B') {
                for (int k = 0; k < 4; k++) {
                    int xx = i + dx[k], yy = j + dy[k];
                    if (chk(xx, yy)) continue;
                    if (s[xx][yy] == 'G') {
                        good.push_back({xx,yy});
                        fl = 0;
                        break;
                    }
                    if (s[xx][yy] == '.') {
                        s[xx][yy] = '#';
                    }
                }
            }
        }
    }
    dis[n][m] = 0;
    queue<pii> q;
    while(q.size())q.pop();
    pii zz = {n, m};
    q.push(zz);
    int pz = (int)good.size();
    if (s[n][m] == '#' && pz > 0) {
        fl = 0;
    }
    if(!fl){
        cout << "No" << endl;return ;
    }
    // cout << "FUCK " << endl;
    st[n][m] = 1;
    while (q.size()) {
        auto [aa, bb] = q.front();
        q.pop();
        st[aa][bb] = 0;
        for (int i = 0; i < 4; i++) {
            int xx = aa + dx[i];
            int yy = bb + dy[i];
            if (chk(xx, yy)) continue;
            if (dis[xx][yy] > dis[aa][bb] + 1) {
                dis[xx][yy] = dis[aa][bb] + 1;
                if (!st[xx][yy]) {
                    st[xx][yy] = 1;
                    q.push({xx, yy});
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i][j] == 'G' && dis[i][j] == INF){
                fl = 0;
            }
        }
    }
    cout << (fl ? "Yes" : "No") <<endl;
}
// bool dfs(int r, int c) {
//     if(vis[r][c]) return 1;
//     vis[r][c] = 1;
//     //  cout << "r == " << r << " c== " << c << endl;
//     // if(r<0||r>=n||c<0||c>=m||map[r*m+c]=='#'||vis[r*m+c]) return 0;
//     if ((!chk(r, c)) || s[r][c] == '#') return 0;
//     if (r == n && c == m) return 1;
//     // if(r!=0||c!=0) vis[r*m+c]=1;
//     return dfs(r + 1, c) || dfs(r, c + 1) || dfs(r - 1, c) || dfs(r, c - 1);
// }
// void solve() {
//     memset(vis , 0 , sizeof vis);
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) {
//         cin >> s[i] + 1;
//     }
//     vector<pii> good;
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             if (s[i][j] == 'G') {
//                 good.push_back({i, j});
//             }
//             if (s[i][j] == 'B') {
//                 for (int k = 0; k < 4; k++) {
//                     int xx = i + dx[k], yy = j + dy[k];
//                     if (!chk(xx, yy) && s[xx][yy] == '.') {
//                         s[xx][yy] = '#';
//                     }
//                 }
//             }
//         }
//     }
//     // for(int i = 1; i<=n; i++){
//     //     for(int j = 1; j <= m; j++){
//     //         cout << s[i][j] ;
//     //     }cout << endl;
//     // }
//     int fl = 1;
//     for(auto [a,b] : good){
//         if(dfs(a,b) == 0){
//             fl = 0;
//             break;
//         }
//     }
//     cout <<(fl?"Yes":"No") <<endl;
// }
int main() {
    close;
    CASET { solve(); }
}