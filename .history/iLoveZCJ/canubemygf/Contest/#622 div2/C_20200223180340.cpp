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
#define int long long 
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
constexpr int maxn = 1e6+1e5;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9+7;
deque<int >de1 , de2;
int n ,ks,mx le[maxn], ri[maxn], m[maxn],a[maxn],ans1[maxn],ans2[maxn];
int32_t main()
{
    close;
    int zcj = 0,zz=0;
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> m[i];
    de2.eb(n+1);
    de1.emplace_back(0);
    for(int i = 1; i <= n; i++){
        le[i] = zcj;
        ri[i] = n+1;
        while(!de1.empty()){
            if(m[de1.back()] > m[i]){
                de1.pop_back();
            }else break;
        }
        int kp = de1.back();
        ans1[i] = ans1[kp] + (i-kp)*m[i];
        zz++;//cout << zz << endl;
        de1.eb(i);
    }
    for(int i = n; i > 0;--i){
        while(!de2.empty()){
            if(m[de2.back()] > m[i]){
                de2.pop_back();
                zz++;//cou<<"ss" <<zz<<endl;
            }else break;
        }
        zcj++;//cout <<"zcj == " << zcj << endl;
        int kp = de2.back();
        ans2[i] = ans2[kp]+(kp-i)*m[i];
        de2.eb(i);
        ks++;
    }
    
    
}