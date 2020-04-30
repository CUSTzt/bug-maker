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
int main()
{
    #include<bits/stdc++.h>
#define LL long long
#define PB push_back
#define POP pop_back()
#define PII pair<int,int>
using namespace std;
const int INF=0x3f3f3f3f;
const double pi=acos(-1),eps=1e-8;
const int N=1e6+10,M=6e6+10,mod=201314;
int n,m;
char a[N];
int main()
{
    scanf("%s",a+1);
    n=strlen(a+1);
    LL ans=0;
    for(int i=0;i<26;i++){
        LL cnt=0;
        for(int j=1;j<=n;j++){
            if(a[j]-'a'==i)cnt++;
        }
        ans=max(ans,cnt);
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            LL x=0,y=0;
            for(int k=1;k<=n;k++){
                if(a[k]-'a'==j)y+=x;
                if(a[k]-'a'==i)x++;
 
            }
            ans=max(ans,y);
        }
    }
    cout<<ans;
    return 0;
}
    
}