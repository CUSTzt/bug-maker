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
struct ZCJ{
    int color , x , y;
}zz[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> mu[i].x >> mu[i].y;
        mu[i].key = i;
    }
    sort(mu , mu + n,cmp);
    int col = 1;
    a[mu[0].key ] = 1;
    zz[1].color = col;
    zz[1].x = mu[0].x,zz[1].y = mu[0].y;
    for(int i = 1; i < n; i++){
        int fl = 0;
        for( int j = 1; j <= col; j++){
            if(mu[i].x < zz[j].x && mu[i].y < zz[j].y){
                fl = 1;
                zz[j].x = mu[i].x;
                zz[j].y = mu[i].y;
                a[mu[i].key] = col;
            }
        }
        if(!fl){
            col++;
            zz[col].x = mu[i].x;
            zz[col].y = mu[i].y;
            a[mu[i].key] = col;
        }
    }
    cout << col << endl;
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
}