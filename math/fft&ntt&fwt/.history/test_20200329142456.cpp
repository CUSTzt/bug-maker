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
using namespace std;
using LL = long long;
#define eps 1e-8
#define fi first
#define se second
#define eb emplace_back
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
typedef vector<int> vi;
typedef pair<int, int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x; }
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
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7;
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void dec(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}
void FFT(complex* A, int type) {
    for (int i = 0; i < limit; i++)
        if (i < r[i]) swap(A[i], A[r[i]]);
    for (int mid = 1; mid < limit; mid <<= 1) {
        complex Wn(cos(Pi / mid), type * sin(Pi / mid));
        for (int R = mid << 1, j = 0; j < limit; j += R) {
            complex w(1, 0);
            for (int k = 0; k < mid; k++, w = w * Wn) {
                complex x = A[j + k], y = w * A[j + mid + k];
                A[j + k] = x + y;
                A[j + mid + k] = x - y;
            }
        }
    }
    if (type == -1) {
        for (int i = 0; i < limit; i++) A[i] = A[i] / limit;
    }
}
ll omega[2][21][1 << 20];
void pre()  //预处理单位根，可以显著优化NTT常数
{
    for (int mid = 1, i = 0; i <= 20; mid <<= 1, i++) {
        ll w1 = quick_pow(3, (MOD - 1) / (mid << 1));
        ll w2 = quick_pow(3, MOD - 1 - (MOD - 1) / (mid << 1));
        omega[0][i][0] = omega[1][i][0] = 1;
        for (int k = 1; k < mid; k++) {
            omega[1][i][k] = omega[1][i][k - 1] * w1 % MOD;
            omega[0][i][k] = omega[0][i][k - 1] * w2 % MOD;
        }
    }
}
void NTT(ll* A, int type) {
    for (int i = 0; i < limit; i++)
        if (i < r[i]) swap(A[i], A[r[i]]);
    if (type == -1) type = 0;
    for (int mid = 1, i = 0; mid < limit; mid <<= 1, i++) {
        for (int R = mid << 1, j = 0; j < limit; j += R) {
            for (int k = 0; k < mid; k++) {
                ll x = A[j + k] % MOD,
                   y = omega[type][i][k] * A[j + mid + k] % MOD;
                A[j + k] = x + y;
                A[j + mid + k] = x - y;
            }
        }
    }
    for (int i = 0; i < limit; i++) {
        A[i] %= MOD;
        if (A[i] < 0) A[i] += MOD;
    }
    if (type == 0) {
        ll inv = quick_pow(limit, MOD - 2);
        for (int i = 0; i < limit; i++) A[i] = A[i] * inv % MOD;
    }
}
void FWT_or(ll* A, int type) {
    for (int mid = 1; mid < limit; mid <<= 1)
        for (int R = mid << 1, j = 0; j < limit; j += R)
            for (int k = 0; k < mid; k++)
                if (type == 1)
                    A[j + mid + k] += A[j + k];
                else
                    A[j + mid + k] -= A[j + k];
    for (int i = 0; i < limit; i++) {
        A[i] %= MOD;
        if (A[i] < 0) A[i] += MOD;
    }
}
void FWT_and(ll* A, int type) {
    for (int mid = 1; mid < limit; mid <<= 1)
        for (int R = mid << 1, j = 0; j < limit; j += R)
            for (int k = 0; k < mid; k++)
                if (type == 1)
                    A[j + k] += A[j + mid + k];
                else
                    A[j + k] -= A[j + mid + k];
    for (int i = 0; i < limit; i++) {
        A[i] %= MOD;
        if (A[i] < 0) A[i] += MOD;
    }
}
void FWT_xor(ll* A, int type) {
    for (int mid = 1; mid < limit; mid <<= 1)
        for (int R = mid << 1, j = 0; j < limit; j += R)
            for (int k = 0; k < mid; k++) {
                ll x = A[j + k], y = A[j + mid + k];
                A[j + k] = x + y;
                A[j + mid + k] = x - y;
                if (A[j + k] > MOD) A[j + k] -= MOD;
                if (A[j + mid + k] < 0) A[j + mid + k] += MOD;
                if (type == -1) {
                    A[j + k] = A[j + k] * inv2 % MOD;
                    A[j + mid + k] = A[j + mid + k] * inv2 % MOD;
                }
            }
}

int main() {}