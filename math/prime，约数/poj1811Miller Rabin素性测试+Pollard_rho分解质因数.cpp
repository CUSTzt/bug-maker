#include <iostream>
#include <ctime>
#include <algorithm>
#define LL long long
const int S=20;
LL factor[100];
int tot;
LL n;
using namespace std;
 
LL quickmult(LL a,LL b,LL mod)
{
    a%=mod;
    b%=mod;
    LL ans=0;
    while(b)
    {
        if(b&1)
        {
            ans+=a;
            ans%=mod;
        }
        b/=2;
        a=(a+a)%mod;
    }
    return ans;
}
LL quickpow(LL a,LL b,LL mod)
{
    LL ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=quickmult(ans,a,mod)%mod;
        }
        b/=2;
        a=quickmult(a,a,mod)%mod;
    }
    return ans;
    /*if(n==1)
        return a%mod;
    LL temp=a;
    LL ret=1;
    while(b)
    {
        if(b&1)
            ret=quickmult(ret,temp,mod);
        temp=quickmult(temp,temp,mod);
        b/=2;
    }
    return ret;*/
}
bool check(LL a,LL n,LL x,LL T)
{
    LL temp1=quickpow(a,x,n);
    LL temp2=temp1;
    while(T--)
    {
        temp1=quickmult(temp1,temp1,n);
        if(temp1==1&&temp2!=1&&temp2!=n-1)
            return true;
        temp2=temp1;
    }
    if(temp1!=1)
        return true;
    return false;
}
bool Miller_Rabin(LL n)
{
    if(n<2)
        return false;
    if(n==2)
        return true;
    if((n&1)==0)
        return false;
    LL x=n-1;
    LL t=0;
    while((x&1)==0)
    {
        x>>=1;
        t++;
    }
    for(int i=0;i<S;i++)
    {
        LL a=rand()%(n-1)+1;
        if(check(a,n,x,t))
            return false;
    }
    return true;
}
LL gcd(LL a,LL b)
{
   /* if(b==0)
        return a;
    return gcd(b,a%b);*/
    if(a==0)
        return 1;
    if(a<0)
        return gcd(-a,b);
    while(b)
    {
        LL temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
LL Pollard_rho(LL x,LL c)
{
    LL i=1,k=2;
    LL x0=rand()%x;
    LL y=x0;
    while(true)
    {
        
        i++;
        x0=(quickmult(x0,x0,x)+c)%x;
        LL d=gcd(y-x0,x);
        if(d!=1&&d!=x)
           return d;
        if(y==x0)
            return x;
        if(i==k)
        {
            y=x0;
            k+=k;
        }
    }
}
void findfac(LL n)
{
    if(Miller_Rabin(n))
    {
        factor[tot++]=n;
        return ;
    }
    LL p=n;
    while(p>=n)
    {
        p=Pollard_rho(p,rand()%(n-1)+1);
    }
    findfac(p);
    findfac(n/p);
}
int main()
{
    int T;
    while(cin>>T)
    {
        while(T--)
        {
            cin>>n;
            tot=0;
            findfac(n);
            if(tot==1)
                cout<<"Prime"<<endl;
            else
            {
                sort(factor,factor+tot);
                cout<<factor[0]<<endl;
            }
        }
    }
    return 0;
}