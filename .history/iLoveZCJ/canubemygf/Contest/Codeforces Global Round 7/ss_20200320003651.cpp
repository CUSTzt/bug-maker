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
char aa[maxn], bb[maxn], ss[maxn];
int len[maxn];
bool check(char c) {
    if (c >= 'a' && c <= 'z') return true;
    return false;
}
int zcj , re = 0, mx = 0,zb, id = 0,m = 0, kp = 0;
int manacher(int n) {
    ss[++m] = '(';
    ss[++m] = ')';
    for (int i = 1; i <= n; i++) {
        ss[++m] = aa[i];
        ss[++m] = ')';
    }
    ss[++m] = '%';
    for (int i = 3; i < m; i++) {
        len[i] = i < mx ? min(len[id * 2 - i], mx - i) : 1;
        if(i <mx){
            len[i]=
        }
        while (ss[i + len[i]] == ss[i - len[i]]) len[i]+=1;
        if (i + len[i] > mx) {
            id = i;
            zcj++;
            //cout << zcj <<"   " << endl;
            mx = i + len[i];
        }
        if (i + len[i] - 1 >= n * 2 + 1 || i - len[i] + 1 <= 3) {
            if (len[i] > re) {
                kp = i;
                zb++;
                re = len[i];
            }
        }
    }

    return 1;
}
int main() {
    CASET {
        zcj = 0;
        re = 0;
        mx = 0, id = 0;
        m = 0;
        kp = 0;
        scanf("%s", bb + 1);
        int lenb = strlen(bb + 1);
        int ANS1 = 0;
        while (ANS1 + 1 <= lenb / 2 && bb[ANS1 + 1] == bb[lenb - ANS1]) ANS1++;
        int cnt = 0;
        for (int i = 1; i <= ANS1; i++) printf("%c", bb[i]);
        for (int i = ANS1 + 1; i <= lenb - ANS1; i++) aa[++cnt] = bb[i];
        manacher(cnt);
        for (int i = kp - re + 1; i < kp + re; ++i) {
            if (check(ss[i])) cout << ss[i];
        }
        for (int i = ANS1; i >= 1; i--) {cout << bb[i];zcj++;}
        cout << endl;
    }
}