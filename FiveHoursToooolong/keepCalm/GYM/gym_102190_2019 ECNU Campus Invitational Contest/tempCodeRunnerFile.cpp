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
int main() {
    close;
    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        vector<int > a(7);
        for(int i = 1; i <= 6; i++){
            cin >>a[i];
        }
        ans+=a[6];
        a[6]=0;
        ans+=a[5];
        a[1]-=a[5];
        ans+=(a[3]/2);
        a[3]%=2;
        ans+=a[4];
        // printf("a[2]===%d",a[2]);
        if(a[4]>=a[2]){
            a[2]=0;
            a[1]-=2*(a[4]-a[2]);
        // printf("    a[2]===%d",a[2]);

        }else {
            a[2]-=a[4];
        }
        if(a[3] == 1){
            ans+=1;
            if(a[2]>=1){
                a[2]--;
                a[1]--;
            }else{
                a[1]-=3;
            }
        }
        if(a[2]>0){
            ans+=(a[2]/3);
            a[2]%=3;
        }
        if(a[2] == 1){
            a[1]-=4;
            ans++;
        }
        if(a[2]==2){
            a[1]-=2;
            ans++;
        }
        if(a[1]>=0){
            ans+=ceil(a[1]/6.0);
        }
        // cout <<endl;
        cout << ans << endl;
    }
}












