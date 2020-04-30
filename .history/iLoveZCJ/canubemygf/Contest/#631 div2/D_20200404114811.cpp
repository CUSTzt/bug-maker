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
#define CASET int ___T; cin>>___T; for(int __CS=1;__CS<=___T;__CS++)
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

int n, q, a[maxn], num[maxn], r[maxn], dp[25][maxn], le ,rr,k, ans;
int get(int r, int l){return log(r - l + 1) / log(2);}
void pre(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        memset(num, 0, sizeof(num));
        memset(r, 0x3f, sizeof(r));
        r[200000] = i;
        dp[0][i] = 1;
        int j = i;
        while (j >= 0) {
            j--;
            if (a[j] > a[i])
                num[j] = num[j + 1] - 1;
            else
                num[j] = num[j + 1] + 1;
            r[num[j] + 200000] = j;
            if (num[j] == 0) dp[0][i] = max(dp[0][i], i - j + 1);
        }
        j = i;
        while (j < n) {
            j++;
            if (a[j] >= a[i])
                num[j] = num[j - 1] + 1;
            else
                num[j] = num[j - 1] - 1;
            dp[0][i] = max(dp[0][i], j - r[num[j] + 200000] + 1);
        }
    }
    for (int i = 1; i < 22; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
}
int main() {
    close;
    pre();
    int _;
    cin >>_;
    while (_--) {
        cin >> le >> rr;
        k = get(rr,le);
        ans = max(dp[k][le], dp[k][rr + 1 - (1 << k)]);
        cout << ans << endl;
    }
    return 0;
}
