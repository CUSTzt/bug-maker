
/*/
 为了情况最坏，无论你到哪，一定会在你前往绿洲的最短路上的那片沙子上刮风，
 所以这个点到绿洲的最短路即为他相连的点中到绿洲距离最短的距离+3和次短的距离+1的最小值
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<ctime>
#include<vector>
#include<set>
#include<map>
#include<stack>
using namespace std;
#define sp cout<<"---------------------------------------------------"<<endl;
const int inf=0x3f3f3f3f;
const int dx[]={-1,0,1,-1,1,-1,0,1},dy[]={-1,-1,-1,0,0,1,1,1};
class DesertWind {
    public:
        int a[110][110],ans[110][110],n,m;
        bool is(int x,int y){
            if(x<1||y<1||x>n||y>m||a[x][y]==inf)return false;
            return true;
        }
        int daysNeeded(vector<string>theMap){
            n=theMap.size(),m=theMap[0].length();
            int i,j,sx,sy,k;
            memset(ans,0x3f,sizeof(ans));
            memset(a,0x3f,sizeof(a));
            for(i=0;i<n;i++)
              for(j=0;j<m;j++)
                if(theMap[i][j]=='@')sx=i+1,sy=j+1,a[i+1][j+1]=0;
                  else if(theMap[i][j]=='-')a[i+1][j+1]=0;
                  else if(theMap[i][j]=='*'){
                    a[i+1][j+1]=0;
                    ans[i+1][j+1]=0;
                  }
            for(int _=1;_<=n*m;_++)
              for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
                  if(a[i][j]!=inf){
                      int cnt=0,d[10];
                      for(k=0;k<=8;k++)d[k]=inf;
                      for(k=0;k<8;k++){
                        int x=i+dx[k],y=j+dy[k];
                        if(is(x,y))d[++cnt]=ans[x][y];
                    }
                    sort(d+1,d+cnt+1);
                    ans[i][j]=min(ans[i][j],min(d[1]+3,d[2]+1));
                  }
            return ans[sx][sy]==inf?-1:ans[sx][sy];
        }
};