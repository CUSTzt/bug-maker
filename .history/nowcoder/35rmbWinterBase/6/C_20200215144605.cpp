#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
using LL = long long;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; scanf("%d", &___T); for(int __CS=1;__CS<=___T;__CS++)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
int a[maxn];
struct node{
    int x, y, key;
}mu[maxn];
bool cmp(node a , node b){
    if(a.x == b.x){
        return a.y>b.y;
    }
    return a.x > b.x;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> mu[i].x >> mu[i].y;
        mu[i].key = i;
    }
    sort(mu , mu + n);
    int col = 1;
    map<int , pair<int , int > >mp;
    mp[1] = {mu[0].x , mu[0].y};
    a[mu[0].key] = 1;
    for(int i = 1; i < n ; i++){
        auto it = mp.begin();
        for( ; it != mp.end();it++){
            if(mu[i].x < it->first && mu[i].y < it.second)
        }
        if(it == mp.end()){
            a[mu[i].key] = ++col;
        }
    }
    cout << col << endl;
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
}