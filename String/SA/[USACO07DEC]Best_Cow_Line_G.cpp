#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e6+100;
struct SA{//后缀数组的板子
    int sa[N];
    int t1[N],t2[N],c[N];
    int rk[N],ht[N];
    void build(int s[],int n,int m)
    {
        int i,j,p,*x=t1,*y=t2;
        for(i=0;i<m;i++)c[i]=0;
        for(i=0;i<n;i++)c[x[i]=s[i]]++;
        for(i=1;i<m;i++)c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
        for(j=1;j<=n;j<<=1)
        {
            p=0;
            for(i=n-j;i<n;i++)y[p++]=i;
            for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
            for(i=0;i<m;i++)c[i]=0;
            for(i=0;i<n;i++)c[x[y[i]]]++;
            for(i=1;i<m;i++)c[i]+=c[i-1];
            for(i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
            swap(x,y);
            p=1;x[sa[0]]=0;
            for(i=1;i<n;i++)
                x[sa[i]]=y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+j]==y[sa[i]+j]?p-1:p++;
            if(p>=n)break;
            m=p;
        }
    }
    void getHeight(int s[],int n)
    {
        int i,j,k=0;
        for(i=0;i<=n;i++)rk[sa[i]]=i;
        for(i=0;i<n;i++)
        {
            if(k)k--;
            j=sa[rk[i]-1];
            while(s[i+k]==s[j+k])k++;
            ht[rk[i]]=k;
        }
    }
}sa;
char s[N];
int ss[N];
int main(){
    // scanf("%s", s);
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n ;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    s[n] = 'Z'+10;
    for(int i = 2*n;i > n; i--) s[i] = s[2*n-i];
    for(int i = 0; i <= 2*n; i++) ss[i] = s[i] - '\0';
    sa.build(ss, 2*n+1 , max(200,n));
    int l = 0, r = n-1, tot = 0;
    while (l <= r) {
    printf("%c", sa.rk[l] < sa.rk[n - r] ? s[l++] : s[r--]);
    if ((++tot) % 80 == 0) puts("");
    }

}