// // // // She is Pretty pretty!
// // // #include<bits/stdc++.h>
// // // using namespace std;

// // // #define ll long long
// // // #define ff first
// // // #define ss second
// // // #define mp make_pair
// // // #define pb push_back

// // // const int N = 1e6+100;
// // // void umax(int &a, int b) {if(a < b) a=b;}

// // // void up() {
// // //     int n , x;
// // //     cin >> n >> x;
// // //     vector<int> a(n+1), b(x);
// // //     int sum = 0;
// // //     // int ans = -1;
// // //     map<int , int> mp1, mp2;
// // //     mp1[0] = 0;
// // //     for(int i = 1; i <= n; i++){
// // //         cin >> a[i];
// // //         sum+=a[i];
// // //         if(mp1.count(sum % x) == 0){
// // //             mp1[sum % x] = i-1;
// // //         }
// // //     }
// // //     int tp = 0;
// // //     for(int i = n; i >= 1; i--){
// // //         tp += a[i];
// // //         if(mp2.count(tp % x) == 0){
// // //             mp2[tp % x] = i+1;
// // //         }
// // //     }
// // //     int ans = -1;
// // //     for(auto it: mp1){
// // //         if(mp2.count(it.first))umax(ans , it.second - mp2[it.first]);
// // //     }
// // //     for(auto it: mp2){
// // //         if(mp1.count(it.first))umax(ans , mp2[it.first]-it.second);
// // //     }
// // //     cout << ans << endl;
// // // }
// // // int main() {
// // //     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// // //     int _; cin >> _; while (_--) up();
// // //     return 0;
// // // }
// // //~ while (clock()<=69*CLOCKS_PER_SEC)
// // //~ #pragma comment(linker, "/stack:200000000")
// // #pragma GCC optimize("O3")
// // #pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
// // //~ #pragma GCC target ("avx2")
// // //~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// // #include <algorithm>
// // #include <stack>
// // #include <queue>
// // #include <map>
// // #include <set>
// // #include <vector>
// // #include <random>
// // #include <cmath>
// // #include <chrono>
// // #include <cstring>
// // #include <string>
// // #include <iostream>
// // #include <cstdio>
// // #include <cstring>
// // #include <cassert>
// // //#include <ext/pb_ds/assoc_container.hpp>
// // //#include <ext/pb_ds/tree_policy.hpp>
// // //using namespace __gnu_pbds;
// // using namespace std;
// // using LL = long long;
// // #define eps 1e-8
// // #define fi first
// // #define se second
// // #define eb emplace_back
// // #define SZ(a) int(a.size())
// // #define ALL(x) (x).begin(),(x).end()
// // #define trav(a,x) for (auto& a: x)
// // #define LOG(FMT...) fprintf(stderr, FMT)
// // #define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
// // #define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
// // #define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
// // #define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
// // #define CASET int ___T; cin>>___T; for(int __CS=1;__CS<=___T;__CS++)
// // typedef long long ll;
// // typedef unsigned long long ull;
// // typedef vector<int> vi;
// // typedef pair<int,int> pii;
// // mt19937 dlsrand(random_device{}());
// // mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
// // int rnd(int x) { return mrand() % x;}
// // ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// // LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
// // inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
// // const double PI = acos(-1.0);
// // constexpr int maxn = 1e6+10;
// // constexpr int INF = 0x3f3f3f3f;
// // constexpr int mod = 1e9+7;
// // constexpr int Erica = 998244353;
// // constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
// // constexpr ull base=2333, P_1=19260811, P_2=999998639;
// // void umax(int &a, int b) {if(a < b) a=b;}
// // void umin(int &a, int b) {if(a > b) a=b;}
// // void add(int &a,int b) {a+=b; if(a>=mod) a-=mod;}
// // void dec(int &a,int b) {a-=b; if(a<0) a+=mod;}
// // int a[maxn];
// // int main()
// // {
// //     close;
// //     CASET{
// //         int n , x;
// //         cin >> n >> x;
// //         // int ans = -1;
// //         map<int , int > mp;
// //         int sum = 0;
// //         mp[0] = 0;
// //         int kp = INF, ans = -1;
// //         for(int i = 1; i <= n; i++){
// //             cin >> a[i];
// //             sum+=a[i];
// //             if(sum % x != 0 && kp == INF){
// //                 kp = i;
// //                 ans = kp;
// //             }
// //             if(sum % x != 0){
// //                 umax(ans , i);
// //                 // cout << "ks  1" <<endl;
// //             }
// //             if(sum % x == 0){
// //                 umax(ans, i - kp);
// //             }
// //             // cout << " i == " << i << "  ans == " << ans << endl;
// //         }
        
// //         sum = 0;
// //         kp = -INF;
// //         for(int i = n; i >= 1; i--){
// //             // cin >> a[i];
// //             sum+=a[i];
// //             if(sum % x != 0 && kp == -INF){
// //                 kp = i;
// //                 ans = kp;
// //             }
// //             if(sum % x != 0){
// //                 umax(ans , i);
// //                 // cout << "ks  1" <<endl;
// //             }
// //             if(sum % x == 0){
// //                 umax(ans,  kp - i);
// //             }
// //             // cout << " i == " << i << "  ans == " << ans << endl;
// //         }
// //         cout << ans << endl;
// //     }
    
// // }
// //~ while (clock()<=69*CLOCKS_PER_SEC)
// //~ #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
// //~ #pragma GCC target ("avx2")
// //~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #include <algorithm>
// #include <stack>
// #include <queue>
// #include <map>
// #include <set>
// #include <vector>
// #include <random>
// #include <cmath>
// #include <chrono>
// #include <cstring>
// #include <string>
// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <cassert>
// //#include <ext/pb_ds/assoc_container.hpp>
// //#include <ext/pb_ds/tree_policy.hpp>
// //using namespace __gnu_pbds;
// using namespace std;
// using LL = long long;
// #define eps 1e-8
// #define fi first
// #define se second
// #define eb emplace_back
// #define SZ(a) int(a.size())
// #define ALL(x) (x).begin(),(x).end()
// #define trav(a,x) for (auto& a: x)
// #define LOG(FMT...) fprintf(stderr, FMT)
// #define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
// #define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
// #define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
// #define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
// #define CASET int ___T; cin>>___T; for(int __CS=1;__CS<=___T;__CS++)
// typedef long long ll;
// typedef unsigned long long ull;
// typedef vector<int> vi;
// typedef pair<int,int> pii;
// mt19937 dlsrand(random_device{}());
// mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
// int rnd(int x) { return mrand() % x;}
// ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
// inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
// const double PI = acos(-1.0);
// constexpr int maxn = 1e6+10;
// constexpr int INF = 0x3f3f3f3f;
// constexpr int mod = 1e9+7;
// constexpr int Erica = 998244353;
// constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
// constexpr ull base=2333, P_1=19260811, P_2=999998639;
// void umax(int &a, int b) {if(a < b) a=b;}
// void umin(int &a, int b) {if(a > b) a=b;}
// void add(int &a,int b) {a+=b; if(a>=mod) a-=mod;}
// void dec(int &a,int b) {a-=b; if(a<0) a+=mod;}
// int a[maxn];
// int main()
// {
//     close;
//     CASET{
//         int n , x;
//         cin >> n >> x;
//         int ans = -1;
//         int sum = 0;
//         for(int i = 1; i <= n; i++){
//             cin >> a[i];sum+=a[i];
//         }
//         int l = -1, r = -1;
//         int tp = 0;
//         for(int i = 1; i<= n; i++){
//             tp += a[i];
//             if(l == -1 && (tp % x !=0)){
//                 l = i;break;
//             }
//         }
//         tp = 0;
//         for(int i = n; i ; i--){
//             tp +=a[i];
//             if(r == -1 && (tp % x !=0)){
//                 r = i;break;
//             }
//         }
//         if(l != -1){
//             umax(ans , l);
//         }
//         if(r != -1){
//             umax(ans , n-r+1);
//         }
//         tp = 0;
//         for(int i = 1; i <= n; i++){
//             tp += a[i];
//             if(tp % x){
//                 umax(ans , i);
//             }else{
//                 if(l!=-1)
//                 umax(ans,i-l+1);
//             }
//             if((sum-tp) % x)umax(ans,n+1-i);
//             else {if(r!=-1)umax(ans,n+1-r);}
//         }cout << ans << endl;
//     }
    
// }

//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <random>
#include <cmath>
#include <chrono>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
using LL = long long;
#define eps 1e-8
#define fi first
#define se second
#define eb emplace_back
#define SZ(a) int(a.size())
#define ALL(x) (x).begin(),(x).end()
#define trav(a,x) for (auto& a: x)
#define LOG(FMT...) fprintf(stderr, FMT)
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; cin>>___T; for(int __CS=1;__CS<=___T;__CS++)
typedef long long ll;
typedef unsigned long long ull;
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
constexpr int mod = 1e9+7;
constexpr int Erica = 998244353;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ull base=2333, P_1=19260811, P_2=999998639;
void umax(int &a, int b) {if(a < b) a=b;}
void umin(int &a, int b) {if(a > b) a=b;}
void add(int &a,int b) {a+=b; if(a>=mod) a-=mod;}
void dec(int &a,int b) {a-=b; if(a<0) a+=mod;}
void up(){
    int n , x, sum = 0;
    cin >> n >> x;
    vi a(n+10);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum % x){
        cout << n << endl;
        return ;
    }
    int l = -1, r= -1;
    for(int i = 1; i <= n; i++){
        if(a[i] % x){
            l = i;break;
        }
    }
    for(int i = n; i >= 1; i--){
        if(a[i] % x){
            r = i;break;
        }
    }
    if( l ==  -1){
        cout << -1 << endl;
        return ;
    }
    if(l - 1 >= n-r){
        cout << r-1 << endl;
    }else {
        cout << n-l << endl;
    }
    // cout << max(l-1, n - r) << endl;
}
int main()
{
    close;
    CASET{
        up();
    }
    
}