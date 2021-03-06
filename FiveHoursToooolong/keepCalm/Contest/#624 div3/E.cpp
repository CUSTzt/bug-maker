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
int t , n , d, f[5050],node[5050],dep[5050],ans;
bool flag[5050];
int main()
{
    CASET{
        cin >> n >> d;
        int maxd = 0;
        node[0] = 1;
        for(int i = 2; i<= n; i++){
            f[i] = i/2;
            dep[i]=dep[f[i]]+1;
            d-=dep[i];
            maxd = max(maxd, dep[i]);
        }
        if(d < 0){
            puts("NO");continue;
        }
        for(int i = 1; i<=5+n ; i++){
            flag[i] = 0;
        }
        int now = n;
        while(now){
            node[dep[now]]=now;
            flag[now] = 1;
            now = f[now];
        }
        for(int i = n; i>=1; i--){
            if(flag[i])continue;
            int pre = maxd;
            while(dep[f[i]] < pre && d){
                f[i] = node[dep[f[i]]+1];
                dep[i] = dep[f[i]]+1;
                if(dep[i]>maxd){
                    maxd++;
                    node[maxd]=i;
                    flag[i]= 1;
                }d--;
            }
        }
        if(d){cout << "NO\n";continue;}
        else{
            puts("YES");
            for(int i = 2; i <= n; i++)cout << f[i] << ' ';
            cout << endl;
        }
    }
    
}