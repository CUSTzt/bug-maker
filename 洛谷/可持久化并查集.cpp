#include<bits/stdc++.h>
#define N 301000
using namespace std;
template<typename T>inline void read(T &x)
{
    x=0;
    static int p;p=1;
    static char c;c=getchar();
    while(!isdigit(c)){if(c=='-')p=-1;c=getchar();}
    while(isdigit(c)) {x=(x<<1)+(x<<3)+(c-48);c=getchar();}
    x*=p;
}
int n,m;
int L[N*30],R[N*30],fa[N*30],dep[N*30];
int root[N*30];
namespace Persistant_Union_Set
{
#define Mid ((l+r)>>1)
#define lson L[rt],l,Mid
#define rson R[rt],Mid+1,r
    int cnt;
    void build(int &rt,int l,int r)
    {
        rt=++cnt;
        if(l==r){fa[rt]=l;return ;}
        build(lson);build(rson);
    }
    void merge(int last,int &rt,int l,int r,int pos,int Fa)
    {
        rt=++cnt;L[rt]=L[last],R[rt]=R[last];
        if(l==r)
        {
            fa[rt]=Fa;
            dep[rt]=dep[last];
            return ;
        }
        if(pos<=Mid)merge(L[last],lson,pos,Fa);
        else merge(R[last],rson,pos,Fa);
    }
    void update(int rt,int l,int r,int pos)
    {
        if(l==r){dep[rt]++;return ;}
        if(pos<=Mid)update(lson,pos);
        else update(rson,pos);
    }
    int query(int rt,int l,int r,int pos)
    {
        if(l==r)return rt;
        if(pos<=Mid)return query(lson,pos);
        else return query(rson,pos);
    }
    int find(int rt,int pos)
    {
        int now=query(rt,1,n,pos);
        if(fa[now]==pos)return now;
        return find(rt,fa[now]);
    }
#undef Mid
#undef lson
#undef rson
}
using namespace Persistant_Union_Set;
int main()
{
    read(n);read(m);
    build(root[0],1,n);
    for(int i=1;i<=m;i++)
    {
        static int opt,x,y;
        read(opt);read(x);
        if(opt==1)
        {
            read(y);
            static int posx,posy;
            root[i]=root[i-1];
            posx=find(root[i],x);posy=find(root[i],y);
            if(fa[posx]!=fa[posy])
            {
                if(dep[posx]>dep[posy])swap(posx,posy);
                merge(root[i-1],root[i],1,n,fa[posx],fa[posy]);
                if(dep[posx]==dep[posy])update(root[i],1,n,fa[posy]);
            }
        }
        else if(opt==2)root[i]=root[x];
        else if(opt==3)
        {
            read(y);
            root[i]=root[i-1];
            static int posx,posy;
            posx=find(root[i],x);posy=find(root[i],y);
            if(fa[posx]==fa[posy])puts("1");
            else puts("0");
        }
    }
    return 0;
}