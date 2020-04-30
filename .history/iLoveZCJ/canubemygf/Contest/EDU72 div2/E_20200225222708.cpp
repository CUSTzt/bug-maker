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
constexpr int INF = INT_MAX;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7;
struct Node
{
    int a[2];
    Node() : a{INF, INF} {}
};
Node add(const Node &p, const Node &q)
{
    Node ans;
    if (p.a[0] < q.a[0])
    {
        ans.a[0] = p.a[0];
        ans.a[1] = min(p.a[1], q.a[0]);
    }
    else
    {
        ans.a[0] = q.a[0];
        ans.a[1] = min(q.a[1], p.a[0]);
    }
    return ans;
}
struct SegTree
{
    int sz;
    vector<Node> a;
    Node query(int p, int l, int r, int x, int y)
    {
        if (l >= y || r <= x)
        {
            return Node();
        }
        if (l >= x && r <= y)
        {
            return a[p];
        }
        return query(p * 2, l, (l + r) / 2, x, y) + query(p * 2 + 1, (l + r) / 2, r, x, y);
    }
    Node operator + (const Node &p,const Node &q){
    Node ans;
    if(p.a[0]<q.a[0]){
        ans.a[0]=p.a[0];
        ans.a[1]=min(p.a[1],q.a[0]);
    }else{
        ans.a[0]=q.a[0];
        ans.a[1]=min(q.a[1],p.a[0]);
    }
    return ans;
}
    SegTree(int n)
    {
        sz = 1;
        while (sz < n)
        {
            sz *= 2;
        }
        a.resize(sz * 2);
    }
    void modify(int x, int y)
    {
        a[x + sz].a[0] = y;
        for (int i = (x + sz) / 2; i != 0; i /= 2)
        {
            a[i] = add(a[i * 2], a[i * 2 + 1]);
        }
    }
    Node query(int l, int r)
    {
        return query(1, 0, sz, l, r);
    }
};
int main()
{
    close;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<SegTree> t(9, SegTree(n));
    for (int i = 0; i < n; ++i)
    {
        for (int x = a[i], k = 0; k < 9; ++k, x /= 10)
        {
            if (x % 10 > 0)
            {
                t[k].modify(i, a[i]);
            }
            else
            {
                t[k].modify(i, INT_MAX);
            }
        }
    }
    while (m--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            --x;
            a[x] = y;
            for (int v = y, k = 0; k < 9; ++k, v /= 10)
            {
                if (v % 10 > 0)
                {
                    t[k].modify(x, a[x]);
                }
                else
                {
                    t[k].modify(x, INT_MAX);
                }
            }
        }
        else
        {
            --x;
            int ans = INT_MAX;
            for (int k = 0; k < 9; ++k)
            {
                SegTree zz;
                Node a = t[k].query(x, y);
                if (a.a[1] != INT_MAX)
                {
                    ans = min(ans, a.a[0] + a.a[1]);
                }
            }
            if (ans == INT_MAX)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << ans << endl;
            }
        }
    }
}