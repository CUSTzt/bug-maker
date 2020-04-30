#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAXN 200011
ll n,a[MAXN],cnt_inv[MAXN],m;
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
}t,bit2,bit1;
int main()
{
    cin >> n >> m;
    for(ll i=1;i<=n;++i)
    {
        cin >> a[i];
        t.modify(a[i],1);
        cnt_inv[i]=i-t.Qsum(a[i]);
        bit2.modify(cnt_inv[i],1);
        bit1.modify(cnt_inv[i],cnt_inv[i]);
    }
    for(ll i=1;i<=m;++i)
    {
        int op , x;
        cin >> op >> x;

        if(op==1)
        {
            if(a[x]<a[x+1])
            {
                bit2.modify(cnt_inv[x],-1),bit2.modify(cnt_inv[x]+1,1);
                bit1.modify(cnt_inv[x],-cnt_inv[x]),bit1.modify(cnt_inv[x]+1,cnt_inv[x]+1);
                ++cnt_inv[x];
            }
            else
            {
                bit2.modify(cnt_inv[x+1],-1),bit2.modify(cnt_inv[x+1]-1,1);
                bit1.modify(cnt_inv[x+1],-cnt_inv[x+1]),bit1.modify(cnt_inv[x+1]-1,cnt_inv[x+1]-1);
                --cnt_inv[x+1];
            }
            std::swap(a[x],a[x+1]);
            std::swap(cnt_inv[x],cnt_inv[x+1]);
        }
        else
        {
            if(x>=n)
            {
                puts("0");
                continue;
            }
            ll s=bit1.Qsum(n)-bit1.Qsum(x);
            ll c=bit2.Qsum(n)-bit2.Qsum(x);
            printf("%lld\n",s-c*x);
        } 
    }
    return 0;
}