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
int main()
{
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl << 1 << endl;
        return 0;
    }
    if(n == 2){
        cout << 2 << endl;
        cout << "0" << endl << "11" << endl;
        return 0;
    }
    vector<string >ans;
    string s = "00";
    s.eb()

    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i << endl;
    }
    // cout << n - 1 << endl;
    // string s = "00";
    // vector<string >ans;
    // ans.eb(s);
    // // s="10";
    // ans.eb("110");
    // s="110";
    // for(int i = 4; i <= n; i++){
    //     string t = "1";
    //     s[0] = '0';
    //     // cout << "s == " << s << endl;
    //     t+=s;
    //     // t[1] = '1';
    //     s=t;
    //     ans.emplace_back(s);
    // }
    // for(auto it : ans){
    //     cout << it << endl;
    // }
}