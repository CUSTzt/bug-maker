#include<iostream>
#include<cstring>
using namespace std;
int d[109],f[100];
int main()
{
    memset(f, 0x3f, sizeof f);
    f[1]=1;
    d[1]=1;
    for (int i=2;i<=12;i++) d[i]=d[i-1]*2+1;
    for (int i=2;i<=12;i++)
        for (int j=1;j<i;j++)
        f[i]=min(f[i],2*f[j]+d[i-j]);
    for (int i=1;i<=12;i++) printf("%d\n",f[i]);
    return 0;  
}