/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-15 10:05:25
 * @Description: You build it, You run it.  
 ***********************************************/
//#include <bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll r=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return r;
}
int main()
{
    ll x,y,m,n,l;
    cin>>x>>y>>m>>n>>l;
    ll a=n-m,b=l,c=x-y;
    ll d=exgcd(a,b,x,y);
    if(c%d)
        cout<<"Impossible"<<endl;
    else {
        x=x*c/d;
        ll t=x*d/b;
        x=x-t*b/d;
        if(x<0)
            x+=b/d;
        cout<<x<<endl;
    }
    return 0;
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
