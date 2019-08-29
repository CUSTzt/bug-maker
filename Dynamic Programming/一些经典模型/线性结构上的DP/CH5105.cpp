#include <bits/stdc++.h>
using namespace std;
#define fir(i,a,b) for(int i=a;i<=b;i++)
#define int long long
const int N=110;
const int M=5100;
int n,m,i,j,k,f[N][M],s[N],g[N],a[N][M],b[N][M],ans[M],c[N];
int cmp(int a,int b)
{
    return g[a]>g[b];
}
void print(int n, int m)
{
    if (n==0) 
        return;
    print(a[n][m],b[n][m]);
    if (a[n][m] == n)
    {
        fir(i,1,n) 
            ans[c[i]]++;
    }
    else
        fir(i,a[n][m]+1,n)
            ans[c[i]] = 1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    fir(i,1,n)
        cin>>g[i],c[i]=i;
    sort(c+1,c+1+n,cmp);
    memset(f,0x3f,sizeof(f));
    f[0][0]=0;
    fir(i,1,n)
    {
        s[i]=s[i-1]+g[c[i]];
        fir(j,i,m)
        {
            f[i][j]=f[i][j-i];
            a[i][j]=i;
            b[i][j]=j-i;
            fir(k,0,i-1)
            {
                if (f[i][j]>f[k][j-(i-k)]+(s[i]-s[k+1-1])*k)
                {
                    f[i][j]=f[k][j-(i-k)]+(s[i]-s[k+1-1])*k;
                    a[i][j]=k;
                    b[i][j]=j-(i-k);
                }
            }
        }
    }
    cout<<f[n][m]<<endl;
    print(n,m);
    fir(i,1,n)
        cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}
