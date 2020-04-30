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
int a[maxn];
int main()
{
    close;
    CASET{
        int n;
        cin >> n;
        map<int , int > mp;
        int fl = 0;
        int mx = 1;
        for(int i = 1; i<=n; i++){
            cin >> a[i];
            mp[a[i]]++;
            if(mp[a[i]] == 3)fl = 1;
            if(mp[a[i]] == 2) mx=max(mx,a[i]);
        }
        if(fl){
            cout << "0" << endl;
            continue;
        }
        int f = 0;
        for(auto it:mp){
            if(it.fi <= mx){
                if(it.se < 2){f=1;break;}
            }else break;
        }
        if(f){
            cout << 0 << endl;
            continue;
        }
        map<int , int >mp1,mp2;
        int pos1=-1,pos2=-1,pos3=-1,pos4=-1;
        for(int i = 1; i <= n; i++){

        }
    }
    
}