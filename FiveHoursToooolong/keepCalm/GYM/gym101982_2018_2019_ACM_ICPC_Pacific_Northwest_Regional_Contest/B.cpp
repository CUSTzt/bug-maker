/************************************************
# @Author:      miniLCT
# @DateTime:    2019-10-02 14:13:34
# @Description: You build it.You run it
# @More: If lots of AC,try BF,dfs,DP
***********************************************/
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define eps 1e-8
#define close                    \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
typedef long long ll;
const int MAXN = 1e7 + 10;
const int N = 1e7 + 10;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9 + 7;
int a, b, c, d;
int prime[MAXN],phi[MAXN],miu[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
void genphi(int n)
{
    int p=0;
    memset(phi,0,sizeof(phi));
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {p++; phi[i]=i-1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            phi[i*prime[j]]=phi[i]*(i%prime[j]?prime[j]-1:prime[j]);
            if(i%prime[j]==0) break;
        }
    }
}
void genmiu(int n)
{
    int p=0;
    memset(miu,0,sizeof(miu));
    miu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {p++; miu[i]=-1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            miu[i*prime[j]]=i%prime[j]?-miu[i]:0;
            if(i%prime[j]==0) break;
        }
    }
    for(int i = 2; i < n; i++){
        miu[i] += miu[i-1];
    }
}
int coprime(int a, int b) {
    int ans = 0;
    if (a > b) swap(a, b);
    for (int x = 1, gx; x <= a; x = gx + 1) {
        gx = min(a / (a / x), b / (b / x));
        ans += (miu[gx] - miu[x - 1]) * (a / x) * (b / x);
    }
    return ans;
}
int32_t main() {
// #ifdef local
    int nol_cl = clock();
    sieve(MAXN-1);
    genmiu(MAXN-1);
    cin >> a >> b >> c >> d;
    ll ans = coprime(b, d) - coprime(b, c - 1) - coprime(a - 1, d) +
              coprime(a - 1, c - 1);
    cout << ans << endl;
// #ifdef local
    // printf("Time: %dms\n",
        // int32_t((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
// #endif
}
