// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
1 const int N=20010,P=31,D=1000173169,M=262143;
2 int n,i,pow[N],f[N];char a[N];
3 int hash(int l,int r){return(ll)(f[r]−(ll)f[l−1]*pow[r−l+1]%D+D)%D;}
4 int main(){
5 scanf(”%d%s”,&n,a+1);
6 for(pow[0]=i=1;i<=n;i++)pow[i]=(ll)pow[i−1]*P%D;
7 for(i=1;i<=n;i++)f[i]=(ll)((ll)f[i−1]*P+a[i])%D;
8 }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}