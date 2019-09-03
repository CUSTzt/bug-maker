#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
using namespace std;
 
const int maxn=100100;
const int maxm=7000100;
const int oo=2000000000;
 
int x[maxn];
int y[maxm];
int z[maxm];
int hx=0,hy=0,ty=0,hz=0,tz=0;
int n,m,q,u,v,t;
int mark=0;
 
bool Comp(int a,int b)
{
    return a>b;
}
 
int main()
{   
    scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
    for (int i=1; i<=n; i++) scanf("%d",&x[i]);
    
    sort(x+1,x+n+1,Comp);
    
    for (int i=1; i<=m; i++)
    {
        int id=0;
        int temp=-oo;
        
        if (hx<n) if (x[hx+1]+mark>temp)
        {
            temp=x[hx+1]+mark;
            id=1;
        }
        if (hy<ty) if (y[hy+1]+mark>temp)
        {
            temp=y[hy+1]+mark;
            id=2;
        }
        if (hz<tz) if (z[hz+1]+mark>temp)
        {
            temp=z[hz+1]+mark;
            id=3;
        }
        
        if (i%t==0) printf("%d ",temp);
        
        if (id==1) hx++;
        if (id==2) hy++;
        if (id==3) hz++;
        
        int ny=floor((double)temp*u/v);
        int nz=temp-ny;
        
        mark+=q;
        ty++;
        y[ty]=ny-mark;
        tz++;
        z[tz]=nz-mark;
    }
    
    printf("\n");
    
    for (int i=1; i<=n+m; i++)
    {
        int id=0;
        int temp=-oo;
        
        if (hx<n) if (x[hx+1]+mark>temp)
        {
            temp=x[hx+1]+mark;
            id=1;
        }
        if (hy<ty) if (y[hy+1]+mark>temp)
        {
            temp=y[hy+1]+mark;
            id=2;
        }
        if (hz<tz) if (z[hz+1]+mark>temp)
        {
            temp=z[hz+1]+mark;
            id=3;
        }
        
        if (i%t==0) printf("%d ",temp);
        
        if (id==1) hx++;
        if (id==2) hy++;
        if (id==3) hz++;
    }
    
    return 0;
}

/**
 //Author:XuHt
#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m, q, u, v, t, delta = 0;
priority_queue<ll> pq;
queue<ll> q1, q2;

int main() {
    cin >> n >> m >> q >> u >> v >> t;
    for (int i = 1; i <= n; i++) {
        ll a;
        scanf("%lld", &a);
        pq.push(a);
    }
    for (int i = 1; i <= m; i++) {
        ll maxx = -INF;
        int w;
        if (pq.size() && maxx < pq.top()) {
            maxx = pq.top();
            w = 0;
        }
        if (q1.size() && maxx < q1.front()) {
            maxx = q1.front();
            w = 1;
        }
        if (q2.size() && maxx < q2.front()) {
            maxx = q2.front();
            w = 2;
        }
        if (w == 1) q1.pop();
        else if (w == 2) q2.pop();
        else pq.pop();
        maxx += delta;
        q1.push(maxx * u / v - delta - q);
        q2.push(maxx - maxx * u / v - delta - q);
        delta += q;
        if (i % t == 0) printf("%lld ", maxx);
    }
    cout << endl;
    for (int i = 1; i <= n + m; i++) {
        ll maxx = -INF;
        int w;
        if (pq.size() && maxx < pq.top()) {
            maxx = pq.top();
            w = 0;
        }
        if (q1.size() && maxx < q1.front()) {
            maxx = q1.front();
            w = 1;
        }
        if (q2.size() && maxx < q2.front()) {
            maxx = q2.front();
            w = 2;
        }
        if (w == 1) q1.pop();
        else if (w == 2) q2.pop();
        else pq.pop();
        if (i % t == 0) printf("%lld ", maxx + delta);
    }
    cout << endl;
    return 0;
}
 */