// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;

void up() {
	scanf("%d%d",&n,&m);
        ans=0; res=0;
        for(int i=0;i<n;i++) cin>>c[i];
        for(int i=0;i<n;i++) cin>>mp[i];
        for(int i=0;i<n*m;i++) G[i].clear(),rG[i].clear();
        for(int i=0;i<n*m;i++) vis[i]=-1,incyc[i]=false;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(mp[i][j]=='L') add_edge(get_id(i,j),get_id(i,j-1));
                if(mp[i][j]=='R') add_edge(get_id(i,j),get_id(i,j+1));
                if(mp[i][j]=='U') add_edge(get_id(i,j),get_id(i-1,j));
                if(mp[i][j]=='D') add_edge(get_id(i,j),get_id(i+1,j));
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                int id=get_id(i,j);
                if(vis[id]==-1) solve(id);
            }
        printf("%d %d\n",ans,res);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int _; cin >> _; while (_--) up();
	return 0;
}






