/*#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<map>  
#include<cmath>   
using namespace std;  
long long a,b,c,m,f[10000000];  
map<long long,int> mp;  
long long  qsm(long long x)  //快速幂
{  
  long long sum=1; long long aa=a;   
  while (x>0)  
   {  
     if (x&1)  
      sum=(sum*aa)%c;  
     x=x>>1;  
     aa=(aa*aa)%c;  
   }  
  return sum;  
}  
int main()  
{  
  mp.clear();   
  while (scanf("%lld%lld%lld",&c,&a,&b)!=EOF)  
   {
     mp.clear();  
     if (a%c==0)   //判断a,c 是否互质，因为c 是质数，所以直接判断是否整除即可
     {  
        printf("no solution\n");  
        continue;  
     }  
     int p=false;  
     m=ceil(sqrt(c)); 
	 long long ans;  
     for (int i=0;i<=m;i++)  
      { 
         if (i==0)
          {
          	ans=b%c; mp[ans]=i; continue;
          }
         ans=(ans*a)%c;    
         mp[ans]=i;  
      } 
	 long long t=qsm(m); ans=1;
     for (int i=1;i<=m;i++)  
      {  
        ans=(ans*t)%c;  
        if (mp[ans])  
         {  
            int t=i*m-mp[ans];  
            printf("%d\n",(t%c+c)%c);  
            p=true;  
            break;  
         }  
      }  
     if (!p)   
      printf("no solution\n");  
   }  
}  
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
//baby_step giant_step
// a^x = b (mod n) n为素数，a,b < n
// 求解上式 0<=x < n的解
#define MOD 76543
int hs[MOD],head[MOD],Next[MOD],id[MOD],top;
void insert(int x,int y)
{
    int k = x%MOD;
    hs[top] = x, id[top] = y, Next[top] = head[k], head[k] = top++;
}
int find(int x)
{
    int k = x%MOD;
    for(int i = head[k]; i != -1; i = Next[i])
        if(hs[i] == x)
            return id[i];
    return -1;
}
int BSGS(int a,int b,int n)
{
    memset(head,-1,sizeof(head));
    top = 1;
    if(b == 1)return 0;
    int m = sqrt(n*1.0), j;
    long long x = 1, p = 1;
    for(int i = 0; i < m; ++i, p = p*a%n)insert(p*b%n,i);
    for(long long i = m; ;i += m)
    {
        if( (j = find(x = x*p%n)) != -1 )return i-j;
        if(i > n)break;
    }
    return -1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a,b,n;
    while(scanf("%d%d%d",&n,&a,&b) == 3)
    {
        int ans = BSGS(a,b,n);
        if(ans == -1)printf("no solution\n");
        else printf("%d\n",ans);
    }
    return 0;
}