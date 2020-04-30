/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-07 20:47:05
# @Description: Think twice. Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int main()
{
    #include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  int a,b,c,d,e,f;
  scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
  int ans1=0,ans2=0;double rate=0.0;
  for(int i=0;i*100*a<=f;++i){
    for(int j=0;j*100*b+i*100*a<=f;++j){
      if(i+j==0)continue;
      int sum=j*100*b+i*100*a;
      int lim=min(sum/100*e,f-sum);
      for(int k=0;k*c<=lim;++k){
    int l=(lim-k*c)/d;
    int sugar=l*d+k*c;
    if(double(sugar)/sum>rate){
      rate=double(sugar)/sum;
      ans1=sum+sugar;ans2=sugar;
    }
      }
    }
  }
  if(rate==0)printf("%d %d\n",100*a,0);
  else printf("%d %d\n",ans1,ans2);
  return 0;
}
    
    system("pause");
}
/***************************************************************************
*stuff you should look for
*int overflow, array bounds
*special cases (n=1?), set tle
*do smth instead of nothing and stay organized
***************************************************************************/