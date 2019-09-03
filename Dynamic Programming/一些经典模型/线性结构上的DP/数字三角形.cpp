#include <bits/stdc++.h>

using namespace std;
int n;
int D[110][110];
int *maxSum;
int i,j;

int main()
{
    int t;
    cin>>t;
    while(t--){
    cin>>n;
    for(i=1;i<=n;i++)
            for(j=1;j<=i;j++)
            cin>>D[i][j];
    maxSum=D[n];
    for(int i=n-1;i>=1;--i)
        for(int j=1;j<=i;j++)
        maxSum[j]=max(maxSum[j],maxSum[j+1])+D[i][j];
    cout<<maxSum[1]<<endl;
    }
}
