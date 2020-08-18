#include
#define maxn 1005
using namespace std;
int a[maxn],dp[maxn];
vector<int>location[26];
char s1[maxn],s2[maxn];
void init(){
    for(int i=0;i<=maxn;++i)
        a[i]=dp[i]=0;
}
void LCS(){
    init();
    int i,j,k,w,ans,l,r,mid;
    int lena=strlen(s1),lenb=strlen(s2);
    for(i=0;i<26;i++)location[i].clear();
    for(i=lenb-1;i>=0;--i)location[s2[i]-'a'].push_back(i);
    for(i=0,k=0;s1[i];i++)
        for(j=0;j<location[w=s1[i]-'a'].size();++j,++k)
            a[k]=location[w][j];
    dp[1]=a[0];
    dp[0]=-1;
    for(i=ans=1;i<k;++i){
        l=0;r=ans;
        while(l<=r){
            mid=(l+r)>>1;
            if(dp[mid]>=a[i])r=mid-1;
            else l=mid+1;
        }
        if(r==ans)
            ans++,dp[r+1]=a[i];
        else if(dp[r+1]>a[i])dp[r+1]=a[i];
    }
    cout<<ans<<endl;
}
int main(){
    while(scanf("%s%s",s1,s2)!=EOF)LCS();
    return 0;
}