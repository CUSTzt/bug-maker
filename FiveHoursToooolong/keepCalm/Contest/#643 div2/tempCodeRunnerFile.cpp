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
#define trav(a, x) for (auto a : x)
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
struct node {
    int a1[9], a2[9], a3[9];
    int xf2, xf3;
    int df;
    node() {
        memset(a1, 0, sizeof a1);
        memset(a2, 0, sizeof a2);
        memset(a3, 0, sizeof a3);
        xf2 = 0;
        xf3 = 0;
        df = 0;
    }
};
map<string, node> mp;
int chk(int x) { return (6 - x) * 10; }
int cmp(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } else
        return a.second > b.second;
}
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    string s, t;
    int score;
    int cnt2 = 0, cnt3 = 0;
    while (cin >> s >> t >> score) {
        // cout << s << endl << t << endl << score << endl;
        node zz = {};
        // cout << zz.a1[0] << endl;
        if (mp.count(s)) {
            zz = mp[s];
            // cout << mp[s].a1[1] << "  fu * k\n";
        }
        // cout << zz.a1[2] <<endl;
        int tihao = t[2] - '0';
        if (t[1] == '2') {
            // printf(" before a2[%d] == %d\n", tihao, zz.a2[tihao]);
            zz.a2[tihao] = max(zz.a2[tihao], score);
            // cout << s << "   ";
            // printf("a2[%d] == %d\n", tihao, zz.a2[tihao]);
            if (score == 25) {
                if (!(mp.count(s) && mp[s].xf2)) {
                    cnt2++;
                    zz.xf2 = max(0, (6 - cnt2) * 10);
                }
            }
        }
        if (t[1] == '3') {
            zz.a3[tihao] = max(zz.a3[tihao], score);
            if (score == 30) {
                if (!(mp.count(s) && mp[s].xf3)) {
                    cnt3++;
                    zz.xf3 = max(0, (6 - cnt3) * 10);
                }
            }
        }
        if (t[1] == '1') {
            zz.a1[tihao] = max(zz.a1[tihao], score);
        }
        mp[s] = zz;
    }
    vector<pair<string, int> > xs;
    trav(it, mp) {
        // cout << " --- \n";
        // cout << "name == " << it.first << "  df == " << it.second.df << endl;
        string name = it.first;
        node b = it.second;
        // b.df = 0;
        // cout << name << endl;
        // cout << "fuck  " << b.df << endl;
        int l1 = 0, l2 = 0, l3 = 0;
        for (int i = 1; i <= 8; i++) {
            // cout << b.a1[i] << ' ';
            b.df += b.a1[i];
            l1 += b.a1[i];
        }
        // cout << endl;
        // cout << " now == " << b.df << endl;
        // cout << " l1 === " << b.df << endl;
        if (l1 >= 80) {
            for (int i = 1; i <= 4; i++) {
                // cout << b.a2[i] << ' ';
                b.df += (b.a2[i]);
                l2 += b.a2[i];
            }
            b.df += b.xf2;
        }

        // cout << " now === " << b.df << endl;

        if (l2 >= 40) {
            for (int i = 1; i <= 4; i++) {
                b.df += (b.a3[i]);
                l3 += b.a3[i];
            }
            b.df += b.xf3;
        }
        // cout << " now === " << b.df << endl;
        int ss = b.df;
        // cout << "ss === " << name << "    score == " << ss << endl;
        xs.eb(make_pair(name, ss));
    }
    sort(ALL(xs), cmp);
    trav(i, xs) { cout << i.first << ' ' << i.second << endl; }
}

/*
a l31 30
b l31 30
c l31 30
d l31 30
e l31 30
f l31 30
g l31 30

a l21 25
a l11 5
a l12 5
a l13 10
a l14 10
a l15 15
a l16 15
a l17 20
a l18 20
a l31 0
a l32 30
a l33 30
a l21 25
a l21 20
a l22 25
a l23 25
a l24 20
a l24 25
a l23 20

b l21 25
b l11 5
b l12 5
b l13 10
b l14 10
b l15 15
b l16 15
b l17 20
b l18 20
b l31 0
b l32 30
b l33 30
b l21 25
b l21 20
b l22 25
b l23 25
b l24 20
b l24 25
b l23 20

c l21 25
c l11 5
c l12 5
c l13 10
c l14 10
c l15 15
c l16 15
c l17 20
c l18 20
c l31 0
c l32 30
c l33 30
c l21 25
c l21 20
c l22 25
c l23 25
c l24 20
c l24 25
c l23 20

d l21 25
d l11 5
d l12 5
d l13 10
d l14 10
d l15 15
d l16 15
d l17 20
d l18 20
d l31 0
d l32 30
d l33 30
d l21 25
d l21 20
d l22 25
d l23 25
d l24 20
d l24 25
d l23 20

f l21 25
f l11 5
f l12 5
f l13 10
f l14 10
f l15 15
f l16 15
f l17 20
f l18 20
f l31 0
f l32 30
f l33 30
f l21 25
f l21 20
f l22 25
f l23 25
f l24 20
f l24 25
f l23 20
*/