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
char a[110][110];
int main()
{
    int n, m;
    cin >> n >> m;
    int ks1 = 1, ks2 = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
        if (i == 1)
        {
            int kol1 = 1, kol2 = 0, kol3 = 0, p = 0;
            for (int j = 2; j <= m; j++)
                if (a[i][j] == a[i][j - 1])
                    kol1++;
                else
                {
                    p = j;
                    break;
                }
            if (p <= m)
                kol2 = 1;
            for (int j = p + 1; j <= m; j++)
                if (a[i][j] == a[i][j - 1])
                    kol2++;
                else
                {
                    p = j;
                    break;
                }
            if (p <= m)
            {
                if (a[i][1] == a[i][p])
                    ks1 = 0;
                kol3 = 1;
            }
            for (int j = p + 1; j <= m; j++)
                if (a[i][j] == a[i][j - 1])
                    kol3++;
                else
                {
                    ks1 = 0;
                    break;
                }
            if (kol1 + kol2 + kol3 > m || kol1 != kol2 || kol2 != kol3 || kol1 != kol3)
                ks1 = 0;
        }
        else
        {
            for (int j = 1; j <= m; j++)
                if (a[i][j] != a[i - 1][j])
                    ks1 = 0;
        }
    }
    if (ks1 == 1)
    {
        cout << "YES" << endl;
        return 0;
    }
    for (int j = 1; j <= m; j++)
    {
        if (j == 1)
        {
            int kol1 = 1, kol2 = 0, kol3 = 0, p = 0;
            for (int i = 2; i <= n; i++)
                if (a[i][j] == a[i - 1][j])
                    kol1++;
                else
                {
                    p = i;
                    break;
                }
            if (p <= n)
                kol2 = 1;
            for (int i = p + 1; i <= n; i++)
                if (a[i][j] == a[i - 1][j])
                    kol2++;
                else
                {
                    p = i;
                    break;
                }
            if (p <= n)
            {
                if (a[1][j] == a[p][j])
                    ks2 = 0;
                kol3 = 1;
            }
            for (int i = p + 1; i <= n; i++)
                if (a[i][j] == a[1][j])
                {
                    ks2 = 0;
                    break;
                }
                else if (a[i][j] == a[i - 1][j])
                    kol3++;
                else
                {
                    ks2 = 0;
                    break;
                }
            if (kol1 + kol2 + kol3 > n || kol1 != kol2 || kol2 != kol3 || kol1 != kol3)
                ks2 = 0;
        }
        else
        {
            for (int i = 1; i <= n; i++)
                if (a[i][j] != a[i][j - 1])
                    ks2 = 0;
        }
    }
    if (ks2 == 1)
    {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
}