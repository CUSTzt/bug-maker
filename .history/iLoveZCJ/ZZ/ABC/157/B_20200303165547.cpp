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
int n, a[4][4], b[4][4], x;
int main()
{
    FOR(i, 1, 4)
        FOR(j, 1, 4) cin >> a[i][j];
    cin >> n;
    FOR(i, 0, n)
    {
        cin >> x;
        FOR(i, 1, 4)
        FOR(j, 1, 4)
        {
            if (x == a[i][j])
                b[i][j] = 1;
        }
    }
    /*FOR(i , 1,  4){
    FOR(j , 1 , 4){
        cout << b[i][j] <<' ';
    }cout << '\n';}*/
    int fl = 0;
    FOR(i, 1, 4)
    {
        int tmp = 1;
        if (!b[i][4 - i])
            tmp = 0;
        if (tmp)
            fl = 1;
    }cout <<"fl ==== " << fl <<
    FOR(i, 1, 4)
    {
        int tmp = 1;
        if (!b[i][i])
            tmp = 0;
        if (tmp)
            fl = 1;
    }
    FOR(i, 1, 4)
    {
        if (b[i][1] && b[i][2] && b[i][3])
            fl = 1;
    }
    FOR(i, 1, 4)
    {
        if (b[1][i] && b[2][i] && b[3][i])
            fl = 1;
    }
    puts(fl ? "Yes" : "No");
}