#include<bits/stdc++.h>
#define MAXN 1000010
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
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
}
int main()
{
    sieve(1000005);
    int n , x, ans = 0;
    cin >> n;
    x = n;
    while(x >= 4){
        ans++;
        for(int i = 2; i <= x; i++){
            if(is_prime[i] && is_prime[x-i]){
                x = x-i-i;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}