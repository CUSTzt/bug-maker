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
#define close std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(), c.end()), c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
#define CASET           \
    int ___T;           \
    scanf("%d", &___T); \
    for (int __CS = 1; __CS <= ___T; __CS++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x; }
LL bin(LL x, LL n, LL MOD)
{
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1)
            ret = ret * x % MOD;
    return ret;
}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7;
const int N = 102;

int edge[N][N];
int p[N];
int n, m;
vector<pair<int, int>> vec;

int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
void unit(int x, int y)
{
    int a = find(x);
    int b = find(y);
    if (a != b)
        p[a] = b;
}
int krus(int x)
{
    int cnt = 0;
    int fx = vec[x].first;
    int fy = vec[x].second;
    for (int i = 0; i <= n; i++)
    {
        p[i] = i;
    }
    for (int i = x; i < m; i++)
    {
        int ex = vec[i].first;
        int ey = vec[i].second;
        if (find(ex) != find(ey))
        {
            cnt++;
            if (cnt == n - 1)
                return edge[ex][ey] - edge[fx][fy];
            unit(ex, ey);
        }
    }
    return INF;
}

bool cmd(pair<int, int> a, pair<int, int> b)
{
    return edge[a.first][a.second] < edge[b.first][b.second];
}
int sel()
{
    if (m < n - 1 || krus(0) == INF)
        return -1;
    int ans = INF;
    sort(vec.begin(), vec.end(), cmd);
    for (int i = 0; i < m; i++)
    {
        int a = krus(i);
        if (a == INF)
            continue;
        ans = min(ans, a);
    }
    return ans;
}

int main()
{
    while (~scanf("%d%d", &n, &m) && !(n == 0 && m == 0))
    {
        memset(edge, 0, sizeof(edge));
        vec.clear();
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            edge[x][y] = edge[y][x] = z;
            vec.push_back(make_pair(x, y));
        }
        cout << sel() << endl;
    }
    return 0;
}