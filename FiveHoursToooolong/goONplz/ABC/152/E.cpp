// #include <stack>
// #include <queue>
// #include <map>
// #include <set>
// #include <vector>
// #include <random>
// #include <cmath>
// #include <chrono>
// #include <cstring>
// #include <algorithm>
// #include <string>
// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <cassert>
#include<bits/stdc++.h>
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
#define int long long 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
int rnd(int x) { return mrand() % x;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 1e6+10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9+7;
void add(int &a,int b) {a+=b; if(a>=mod) a-=mod;}
void dec(int &a,int b) {a-=b; if(a<0) a+=mod;}
int a[maxn],b[maxn];
int32_t main()
{
    close;
    int n;
    cin >> n;
    unordered_map<int , int > mp;
    for(int i = 1;i <= n; i++){
        cin >> a[i];b[i] = a[i];
        int m = sqrt(a[i]+0.5);
        for(int j = 2; j <= m; j++){
            if(a[i] % j == 0){
                int ret = 0;
                while(a[i] % j == 0){
                    a[i] /= j;
                    ret++;
                }
                if(mp.count(j)){
                    mp[j] = max(ret , mp[j]);
                }else mp[j] = ret;
            }
        }
        if(a[i] > 1){
            if(mp.count(a[i])){
                mp[a[i]] = max(1ll, mp[a[i]]);
            }else mp[a[i]] = 1;
        }
    }
    int ans = 0;
    // for(auto it : mp)cout << it.first << ' ';cout << endl;
    for(int i = 1; i <= n; i++){
        int zz = 1;
        for(auto p : mp){
            int cs = p.second;
            while(b[i] % p.first == 0) {
                b[i] /= p.first;
                cs--;
            }
            zz = zz * bin(p.first , cs , mod) % mod;
        }
        // cout << "i === " << i << "   zz == " << zz << endl;
        ans = (ans + zz ) % mod;
    }
    cout << ans << endl;
}