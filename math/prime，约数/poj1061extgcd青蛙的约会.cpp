#include<iostream>
#include<cstdio>
#define ll long long 
using namespace std;
ll d,x1,y1;
ll exgcd(ll a, ll b, ll &x,ll &y){
    if(b == 0){x = 1;y = 0;return a;}
    d = exgcd(b, a%b, x, y);
    ll z = x;x = y;y = z-y*(a/b);
    return d;
}

int main()
{
    ll n,m,x,y,l;
    cin>>x>>y>>m>>n>>l;
    ll b=n-m,a=x-y;
    if(b<0)
    {
        b=-b;
        a=-a;
    }//处理负数 
        exgcd(b,l,x1,y1);
    if(a%d!=0)//判断方程有无解。 
        cout<<"Impossible";
    else
        cout<<((x1*(a/d))%(l/d)+(l/d))%(l/d);//处理负数 
}