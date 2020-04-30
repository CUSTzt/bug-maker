#include<bits/stdc++.h>
using namespace std;

int n,q,a[100100],num[100100],r[1000100],f[25][1000100],l,r,k,ans;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(num,0,sizeof(num));
        memset(r,0x7f,sizeof(r));
        r[500000]=i;f[0][i]=1;
        int j=i;
        while(j>1)
        {
            j--;
            if(a[j]>a[i]) num[j]=num[j+1]-1;
            else num[j]=num[j+1]+1;
            r[num[j]+500000]=j;
            if(num[j]==0) f[0][i]=max(f[0][i],i-j+1);
        }
        j=i;
        while(j<n)
        {
            j++;
            if(a[j]>=a[i]) num[j]=num[j-1]+1;
            else num[j]=num[j-1]-1;
            f[0][i]=max(f[0][i],j-r[num[j]+500000]+1);
        }
    }
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=max(f[i-1][j],f[i-1][j+(1<<(i-1))]);
    q = Read();
    while(q--)
    {
        cin >> l >> r;
        k=log(r-l+1)/log(2);
        ans=max(f[k][l],f[k][r-(1<<k)+1]);
        cout << ans << endl;
    }
    return 0;
}
