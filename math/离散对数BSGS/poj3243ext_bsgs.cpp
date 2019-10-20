#include <cstdio>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
#define eps 1e-8
typedef long long ll;
const double PI = acos(-1.0);
const int maxn = 1e6;
const int INF = 0x3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
/*
 *  baby_step giant _step
 *  a^x = b(mod n) n不要求是素数
 *  求解上式0 ≤ x < n的解
 */
#define MOD maxn
ll hs[MOD];
int head[MOD];
ll _next[MOD];
ll id[MOD];
int top;
 
void insert(ll x, ll y)
{
    ll k = x % MOD;
    hs[top] = x;
    id[top] = y;
    _next[top] = head[k];
    head[k] = top++;
    return ;
}
 
ll find(ll x)
{
    ll k = x % MOD;
    for (int i = head[k]; i != -1; i = _next[i])
    {
        if (hs[i] == x)
        {
            return id[i];
        }
    }
    return -1;
}
 
ll BSGS(ll a, ll b, ll n)
{
    memset(head, -1, sizeof(head));
    top = 1;
    if (b == 1)
    {
        return 0;
    }
    ll m = sqrt(n * 1.0), j;
    long long x = 1, p = 1;
    for (int i = 0; i < m; i++, p = p * a % n)
    {
        insert(p * b % n, i);
    }
    for (long long i = m; ; i+=m)
    {
        if ((j = find(x = x * p % n)) != -1)
        {
            return i - j;
        }
        if (i > n)
        {
            break;
        }
    }
 
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    ll X,Z,K;
    while(cin>>X>>Z>>K && X+Z+K>0)
    {
        ll ans = BSGS(X,K,Z);
        if(ans == -1)
        {
            cout<<"No Solution"<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}
