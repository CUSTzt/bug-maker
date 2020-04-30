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
#define lowbit(x) (x)&(-x)
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
int n, op , l , r , pos;
struct BIT{
    int len;
    char a[maxn];
    int c[maxn][26] = {0};
    void insert(int id , int x , int v){
        for(int i = id; i <= len; i+= lowbit(i)){
            c[i][x] += v;
        }return ;
    }
    int query(int id , int x){
        int ans = 0;
        for(int i = id; i <= len; i-=lowbit(i)){
            ans += c[i][x];
        }

    }
}T;
int main()
{
    cin >> T.len;
    scanf("%s",T.a+1);
    for(int i = 1; i <= T.len ; i++){
        int zz = T.a[i] - 'a';
        T.insert(i , zz , 1);
    }
    CASET{
        cin >> op;
        if(op == 1){
            char ch;
            cin >> pos >> ch;
            //更新
            T.insert(pos , T.a[pos]-'a',-1);
            T.insert(pos , v-'a', 1);
        }
    }
}