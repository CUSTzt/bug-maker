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
#define int long long 
int a[maxn];
int32_t main()
{
    close;
    int n;
    cin >> n;
    int sum = 0, ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        ans += n*a[i]%mod*a[i]%mod;
        ans%=mod;
    }
    // cout << sum << endl;
    ans -= bin(sum,2,mod);
    add(ans,mod);
    cout << ans << endl;
    
}