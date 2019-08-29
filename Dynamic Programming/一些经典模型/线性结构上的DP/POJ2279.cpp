//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define il inline
using namespace std;
ll n,cnt,x,y,tmp,num[40],sum[5200];
il ll gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
    while(scanf("%lld",&n)&&n){
        memset(sum,0,sizeof(sum));
        cnt=0,x=1,y=1;
        for(int i=1;i<=n;i++)scanf("%lld",&num[i]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=num[i];j++){
                cnt++;
                for(int k=i+1;k<=n;k++){
                    if(num[k]>=j)sum[cnt]++;
                    else break;
                }
                sum[cnt]+=num[i]-j+1;
            }
        for(int i=1;i<=cnt;i++){
            x*=i;y*=sum[i];
            tmp=gcd(x,y);
            x/=tmp;y/=tmp;
        }
        printf("%lld\n",x/y);
    }
    return 0;
}