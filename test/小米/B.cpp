#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <algorithm>
#include <ctime>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define make make_pair
#define fi first
#define se second
#define vi std::vector<int>;
#define DEBUG cout << "debug" << endl
#define CLOSE ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define CASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
const int N = 1e5 + 5;
const int M = 1e6 + 5;
const int MOD = 1e9 + 7;
const int CM = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template <typename T>
T MAX(T a, T b) { return a > b ? a : b; }
template <typename T>
T MIN(T a, T b) { return a > b ? b : a; }
template <typename T>
T GCD(T a, T b){ return b == 0 ? a : GCD(b, a % b); }
template <typename T>
T LCM(T a, T b){ return a / GCD(a, b) * b; }
template <typename T>
T ABS(T a, T b) { return a > 0 ? a : -a; }
template <typename T>
T ADD(T a, T b, T MOD){ return (a + b) % MOD; }
template <typename T>
T DEL(T a, T b, T MOD) { return ((a - b) % MOD + MOD) % MOD; }
ll a[N], b[N];
ll pow(ll a, ll b, ll p){
    ll ans = 1; a %= p;
    while(b){
        if(b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}
ll inv(ll a, ll p){
    return pow(a, p - 2, p);
}
void solve(int kase){
    ll n, k;
    while(~scanf("%lld%lld", &n, &k)){
        ll ans = pow(k, n, MOD);
        for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        for(int i = 1; i <= n; i++) scanf("%lld", &b[i]);
        if(n == 1) {
            ll now = a[1] * b[1] % MOD;
            now = (now + k) % MOD;
            printf("%lld\n", now);
            continue;
        }
        ll base = pow(k, n - 1, MOD);
        for(int i = 1; i <= n; i++) {
            ll now = a[i] * b[i] % MOD * base % MOD;
            ans = (ans + now) % MOD;
        }
        printf("%lld\n", ans);
    }
}
const bool DUO = 0;
void TIME(){
    clock_t start, finish;
    double totaltime;
    start = clock();

    // 待测程序

    if(DUO) {CASE solve(kase);}
    else solve(1);
    // 待测程序

    finish = clock();
    totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("\nTime:%lfms\n", totaltime * 1000);
}
int main(){
    #ifdef ONLINE_JUDGE
        // CLOSE;
        if(DUO) {CASE solve(kase);}
        else solve(1);
    #else
        // freopen("./data/a.txt", "r", stdin);
        // freopen("./data/a.txt", "w", stdout);
        TIME();
    #endif
    return 0;
}
