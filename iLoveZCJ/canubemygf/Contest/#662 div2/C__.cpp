#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,m,ans,a[N],b[N],c[N];
//直接贪心，从大到小枚举答案x，发现相同数的个数不超过n/x+1，且等于n/x+1的不超过n%x即可
bool check(int x)
{
    int num=n/x,mx=n%x;
    if(a[1]>num+1)return 0;
    if(m>mx&&a[mx+1]>num)return 0;
    return 1;
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n+1;i++)a[i]=b[i]=c[i]=0;
        for(int i=1,x;i<=n;i++)scanf("%d",&x),b[x]++;
        m=ans=0;
        for(int i=1;i<=n;i++)if(b[i])a[++m]=b[i];
        sort(a+1,a+m+1),reverse(a+1,a+m+1);
        for(int i=n-1;~i;i--)
        if(check(i+1)){ans=i;break;}
        printf("%d\n",ans);
    }
}