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
int n , x , y , a , b;
bool check(int x, int y){
    if(x <= n && x >= 1 && y <= n && y >= 1)return true;
    return false;
}
int dx[] = {1,-1,0,0,1,-1,1,-1};
int dy[] = {0,0,1,-1,1,1,-1,-1};
queue<pii >q, qq;
map<pii,int > vis, ZZ;
int main()
{
    cin >> n >>x >> y >> a >> b;
    q.push({x,y});
    vis[{x,y}]=1;
    int fl = 0, fll = 0;
    while(!q.empty()){
        pii o = q.front();
        q.pop();
       // cout << 11 << endl;
        for(int i = 0; i < 8; i ++){
            int xx = o.first+dx[i],yy=o.second+dy[i];
            if(xx==a&& yy==b){
                cout << "gl";
                return 0;
            }
            if(xx==yy)fl=1;
            if(__gcd(xx,yy)!=1 && check(xx, yy) && !vis.count({xx,yy})){
                q.push({xx,yy});
                vis[{xx,yy}]++;
            }
        }
    }
    if(fl == 0){
        cout << "gg\n";
        return 0;
    }
    qq.push({a, b});
    ZZ[{a,b}]=1;
    while(!qq.empty()){
        pii o = qq.front();
        qq.pop();
        for(int i = 0; i < 8; i ++){
            int xx = o.first+dx[i],yy=o.second+dy[i];
            if(xx==yy)
            if(__gcd(xx,yy)!=1 && check(xx,yy) && !ZZ.count({xx,yy})){
                qq.push({xx,yy});
                ZZ[{xx,yy}]++;
            }
        }
    }
    if(fl && fll ){
        cout << "gl";
        return 0;
    }else cout << "gg";
}