#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAXN 200011
ll n,a[MAXN],inv[MAXN],m;
struct BIT
{
    ll t[MAXN];
    #define lowb (i&-i)
    void modify(ll i,ll k)
    {
        if(!i)return;
        while(i<=n)
        {
            t[i]+=k;
            i+=lowb;
        }
    }
    ll Qsum(ll i)
    {
        ll res=0;
        while(i)
        {
            res+=t[i];
            i-=lowb;
        }
        return res; 
    }
}t,bit22,bit2;
int main()
{
    cin >> n >> m;
    for(ll i=1;i<=n;++i)
    {
        cin >> a[i];
        t.modify(a[i],1);
        inv[i]=i-t.Qsum(a[i]);
        bit22.modify(inv[i],1);
        bit2.modify(inv[i],inv[i]);
    }
    for(ll i=1;i<=m;++i)
    {
        int op , x;
        cin >> op >> x;

        if(op==1)
        {
            if(a[x]<a[x+1])
            {
                bit22.modify(inv[x],-1),bit22.modify(inv[x]+1,1);
                bit2.modify(inv[x],-inv[x]),bit2.modify(inv[x]+1,inv[x]+1);
                ++inv[x];
            }
            else
            {
                bit22.modify(inv[x+1],-1),bit22.modify(inv[x+1]-1,1);
                bit2.modify(inv[x+1],-inv[x+1]),bit2.modify(inv[x+1]-1,inv[x+1]-1);
                --inv[x+1];
            }
            std::swap(a[x],a[x+1]);
            std::swap(inv[x],inv[x+1]);
        }
        else
        {
            if(x>=n)
            {
                puts("0");
                continue;
            }
            ll s=bit2.Qsum(n)-bit2.Qsum(x);
            ll c=bit22.Qsum(n)-bit22.Qsum(x);
            printf("%lld\n",s-c*x);
        } 
    }
    return 0;
}
