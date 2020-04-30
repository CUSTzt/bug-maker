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
string work(int x){
    string s1 = to_string(x);
    string s2 = s1;
    reverse(s2.begin(),s2.end());
    s1.append(s2);
    return s1;
}
int a[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool check(int x){
    int year = x /10000;
    if(year % 400 == 0 || (year % 4 == 0 && year %100 != 0))a[2] = 29;
    int mon = (x/100)%100;
    int day = x%100;
    printf("year == %d  mon===%d, day === %d",ye,)
    if(mon == 0 || mon >= 13)return false;
    if(a[mon] < day || a[mon] == 0)return false;
    return true;
}
int main()
{
    int d1, d2;
    cin >> d1 >> d2;
    int l = d1 /10000,r =d1/10000;
    int ans = 0;
    for(int i = l; i <= r;i++){
        int zz = std::stoi(work(i));
        if(zz <= d2 && check(zz))ans++;
    }
    cout<<ans << endl;
    
}