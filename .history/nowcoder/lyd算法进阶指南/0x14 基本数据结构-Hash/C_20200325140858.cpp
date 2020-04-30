#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
char str[1000010];
ull p[1000010];
ull h[1000010],f[1000010];
int ans[1000010];
int od[500010],am[500010];
int n;
inline void reset_p()//od[]存奇数,am[]存偶数
{
    p[0]=1;
    int amcnt=1,odcnt=1;
    for(int i=1;i<=1000000;i++)
    {
        p[i]=p[i-1]*131;
        if(i%2==0)am[amcnt++]=i;
        else od[odcnt++]=i;
    }
}
inline void inithas(int len)//h正序hash，f逆序hash
{
    for(int j=1;j<=len;j++)
        h[j]=h[j-1]*131+(str[j]-'a'+1);
    for(int j=1;j<=len;j++)
        f[j]=f[j-1]*131+(str[len-j+1]-'a'+1);
}

inline ull Find_l(int l,int r)
{
    return f[n-l+1]-f[n-r]*p[n-l+1-(n-r)];//找左边用逆序hash值
}
inline ull Find_r(int l,int r)
{
    return h[r]-h[l-1]*p[r-l+1];//右边正序
}
inline int _ask(int num)//进行判断整个字符串里有没有长度为num的回文串，分奇数和偶数进行判断，下标自己写个字符数一数就行了
{
    if(num%2==0)
    {
        int sbsth=num;
        num/=2;
        for(int i=num;i<=n-num;i++)
            if(Find_l(i-num+1,i)==Find_r(i+1,num+i))return sbsth;
        return 0;
    }
    else 
    {
        int sbsth=num;
        num/=2;
        for(int i=num;i<=n-num-1;i++)
            if(Find_l(i-num+1,i)==Find_r(i+2,i+num+1))return sbsth;
        return 0;
    }
}
inline int binary_Search_od(int left,int right)//二分答案中的奇数
{
    int maxx=1;
    while(left<=right)
    {
        int mid=(left+right)>>1;
        int val=_ask(od[mid]);
        if(val)
        {
            left=mid+1;
            maxx=max(maxx,val);
        }
        else 
            right=mid-1;
    }
    return maxx;
}
inline int binary_Search_am(int left,int right)//二分答案中的偶数
{
    int maxx=1;
    while(left<=right)
    {
        int mid=(left+right)>>1;
        int val=_ask(am[mid]);
        if(val)
        {
            left=mid+1;
            maxx=max(maxx,val);
        }
        else 
            right=mid-1;
    }
    return maxx;
}
int main()
{
    int cnt=0;
    reset_p();
    while(scanf("%s",str+1)&&(strcmp(str+1,"END")!=0))
    {
        cnt++;
        memset(h,0,sizeof(h));
        memset(f,0,sizeof(f));
        n=strlen(str+1);
        inithas(n);
        int ans1=binary_Search_od(1,n/2+1);
        int ans2=binary_Search_am(1,n/2+1);
        printf("Case %d: %d\n",cnt,max(ans1,ans2));
    }
    return 0;
}
