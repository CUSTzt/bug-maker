
#include<bits/stdc++.h>
using namespace std;

const int N=2100,K=1e4+100;
char ch[N][K];
int n,k,len[N];
bitset<K> f[N];
pair<int,int> v[2][K];

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",ch[i]+1);
		len[i]=strlen(ch[i]+1);
	}
	f[n+1][0]=1;
	for(int i=n;i>=1;--i)
		f[i]=f[i+1]|(f[i+1]<<len[i]);
	int cnt=0;
	for(int i=1;i<=n;++i)
		if(f[i+1][k-len[i]]) v[0][++cnt]=make_pair(i,1);
	for(int i=1;i<=k;++i)
	{
		char Ans='z'; int ncnt=0,ID=n+1;
		for(int j=1;j<=cnt;++j)
			Ans=min(Ans,ch[v[i-1&1][j].first][v[i-1&1][j].second]);
		putchar(Ans);
		for(int j=1;j<=cnt;++j)
		{
			int id=v[i-1&1][j].first,pos=v[i-1&1][j].second;
			if(ch[id][pos] != Ans) continue;
			if(pos<len[id]) v[i&1][++ncnt]=make_pair(id,pos+1);
			else ID=min(ID,id);
		}
		for(int j=ID+1;j<=n;++j)
			if(k-i-len[j]>=0 && f[j+1][k-i-len[j]]) v[i&1][++ncnt]=make_pair(j,1);
		cnt=ncnt;
	}
	return 0;
}
