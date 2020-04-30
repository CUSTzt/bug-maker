#include <cstdio>
#define ll long long
#define ls id<<1
#define rs id<<1|1
const int N=5e5+10;
ll mx[N<<2],se[N<<2],sum[N<<2],tag[N<<2],a[N];
ll max(ll x,ll y){return x>y?x:y;}
int cnt[N<<2],n,m;
void updata(int id)
{
    if(mx[ls]>mx[rs])
    {
        mx[id]=mx[ls];
        cnt[id]=cnt[ls];
        se[id]=max(se[ls],mx[rs]);
    }
    else if(mx[ls]<mx[rs])
    {
        mx[id]=mx[rs];
        cnt[id]=cnt[rs];
        se[id]=max(mx[ls],se[rs]);
    }
    else
    {
        mx[id]=mx[ls];
        cnt[id]=cnt[ls]+cnt[rs];
        se[id]=max(se[ls],se[rs]);
    }
    sum[id]=sum[ls]+sum[rs];
}
void build(int id,int l,int r)
{
    if(l==r)
    {
        sum[id]=mx[id]=a[l];
        cnt[id]=1;
        se[id]=0;
        return;
    }
    int mid=l+r>>1;
    build(ls,l,mid),build(rs,mid+1,r);
    updata(id);
}
void pushdown(int id)
{
    if(tag[id])
    {
        if(mx[ls]>tag[id])
        {
            sum[ls]-=(mx[ls]-tag[id])*cnt[ls];
            tag[ls]=mx[ls]=tag[id];
        }
        if(mx[rs]>tag[id])
        {
            sum[rs]-=(mx[rs]-tag[id])*cnt[rs];
            tag[rs]=mx[rs]=tag[id];
        }
        tag[id]=0;
    }
}
void change(int id,int L,int R,int l,int r,ll x)
{
    if(mx[id]<=x) return;
    if(L==l&&R==r&&se[id]<x)
    {
        sum[id]-=(mx[id]-x)*cnt[id];
        tag[id]=mx[id]=x;
        return;
    }
    pushdown(id);
    int Mid=L+R>>1;
    if(r<=Mid) change(ls,L,Mid,l,r,x);
    else if(l>Mid) change(rs,Mid+1,R,l,r,x);
    else change(ls,L,Mid,l,Mid,x),change(rs,Mid+1,R,Mid+1,r,x);
    updata(id);
}
/*ll query(int id,int L,int R,int l,int r)
{
    if(l==L&&r==R) return sum[id];
    pushdown(id);
    int Mid=L+R>>1;
    if(r<=Mid) return query(ls,L,Mid,l,r);
    else if(l>Mid) return query(rs,Mid+1,R,l,r);
    else return query(ls,L,Mid,l,Mid)+query(rs,Mid+1,R,Mid+1,r);
}**/
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    build(1,1,n);
    ll x;
    for(int op,l,r,i=1;i<=m;i++)
    {
        scanf("%d%d%d",&op,&l,&r);
        if(op==1)
        {
            scanf("%lld",&x);
            change(1,1,n,l,r,x);
        }
        else
            K_th(????);
    }
    return 0;
}