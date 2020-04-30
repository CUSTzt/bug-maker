#define MAXN 200011
ll n,a[MAXN],cnt_inv[MAXN];
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
}t,tc,ts;
int main()
{
    n=read();
    ll m=read();
    for(ll i=1;i<=n;++i)
    {
        a[i]=read();
        t.modify(a[i],1);
        cnt_inv[i]=i-t.Qsum(a[i]);
        tc.modify(cnt_inv[i],1);
        ts.modify(cnt_inv[i],cnt_inv[i]);
    }
    for(ll i=1;i<=m;++i)
    {
        ll op=read(),x=read();
        if(op==1)
        {
            if(a[x]<a[x+1])
            {
                tc.modify(cnt_inv[x],-1),tc.modify(cnt_inv[x]+1,1);
                ts.modify(cnt_inv[x],-cnt_inv[x]),ts.modify(cnt_inv[x]+1,cnt_inv[x]+1);
                ++cnt_inv[x];
            }
            else
            {
                tc.modify(cnt_inv[x+1],-1),tc.modify(cnt_inv[x+1]-1,1);
                ts.modify(cnt_inv[x+1],-cnt_inv[x+1]),ts.modify(cnt_inv[x+1]-1,cnt_inv[x+1]-1);
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
            ll s=ts.Qsum(n)-ts.Qsum(x);
            ll c=tc.Qsum(n)-tc.Qsum(x);
            printf("%lld\n",s-c*x);
        } 
    }
    return 0;
}

作者：whsstory
链接：https://www.acwing.com/activity/content/code/content/237934/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。