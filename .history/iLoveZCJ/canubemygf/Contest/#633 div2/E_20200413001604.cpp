#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define LL long long
#define PB push_back
#define POP pop_back()
#define PII pair<int,int>
#define FI first
#define SE second
#define ULL unsigned long long
#define endl '\n'
using namespace std;
const int INF=0x3f3f3f3f;
const double pi=acos(-1),eps=1e-8;
const int maxn=1e5+10;
const int N=1e6+10,M=4e7+7,mod=998244353;
LL n;
LL q2(LL x,LL y){
    //cout<<"2 "<<x<<' '<<y<<endl;
    if(x==1)return 2;
    if(y%12==2)return q2(x/4,(y/12+(y%12>0))*3-1)*4;
    else if(y%12==5)return q2(x/4,(y/12+(y%12>0))*3-1)*4+2;
    else if(y%12==8)return q2(x/4,(y/12+(y%12>0))*3-1)*4+3;
    else return q2(x/4,(y/12+(y%12>0))*3-1)*4+1;
}
LL q3(LL x,LL y){
    //cout<<x<<' '<<y<<endl;
    if(x==1)return 3;
    //cout<<"FUCK "<<y/12<<' '<<(y%12>0)<<endl;
    if(y%12==3)return q3(x/4,(y/12+(y%12>0))*3)*4;
    else if(y%12==6)return q3(x/4,(y/12+(y%12>0))*3)*4+3;
    else if(y%12==9)return q3(x/4,(y/12+(y%12>0))*3)*4+1;
    else return q3(x/4,(y/12+(y%12>0))*3)*4+2;
}
int main()
{
    freopen("out.txt")
    int t;
    t = 1000;
    int n = 1;
    while(t--){
        n++;
        LL x=1;
        while(x*3<n){
            n-=x*3;
            x*=4;
        }
        LL ans=0;
        if(n%3==1){
            ans=n/3+x;
        }
        else if(n%3==2){
            ans=q2(x,n);
        }
        else{
            ans=q3(x,n);
        }
        printf("%lld ",ans);
        if(n % 3 == 0)cout << endl;
    }
    return 0;
}