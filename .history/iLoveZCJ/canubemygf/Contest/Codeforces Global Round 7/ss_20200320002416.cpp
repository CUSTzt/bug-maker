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
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; scanf("%d", &___T); for(int __CS=1;__CS<=___T;__CS++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
int rnd(int x) { return mrand() % x;}
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 1e6+10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9+7;
void add(int &a,int b) {a+=b; if(a>=mod) a-=mod;}
void dec(int &a,int b) {a-=b; if(a<0) a+=mod;}
char aa[maxn], bb[maxn],ss[maxn];
int len[maxn], ANS;
void manacher(int n) {
    int re = 0;
    int mx = 0, id = 0;
    int m = 0;
    ss[++m] = '$';
    ss[++m] = '#';
    for (int i = 1; i <= n; i++) {
        ss[++m] = aa[i];
        ss[++m] = '#';
    }
    ss[++m] = '%';
    ANS = 0;
    for (int i = 3; i < m; i++) {
        len[i] = i < mx ? min(len[id * 2 - i], mx - i) : 1;
        while (ss[i + len[i]] == ss[i - len[i]]) ++len[i];
        if (i + len[i] > mx) {
            id = i;
            mx = i + len[i];
        }
        if (i + len[i] - 1 >= n * 2 + 1 || i - len[i] + 1 <= 3) {
            if (len[i] > re) {re = len[i];ANS = i;}
        }
    }
    for (int i = ANS - re + 1; i < ANS + re ; i++) {
        if (check(ss[])) printf("%c", s[i]);
    }
}
int main()
{
    
    
}