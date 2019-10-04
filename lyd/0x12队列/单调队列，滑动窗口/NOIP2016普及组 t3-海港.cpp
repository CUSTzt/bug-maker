#include <bits/stdc++.h>
using namespace std;
int n,m,ans,in_=1;
int t[100001],k[100001],c[100001];
queue <int> q;
int main()
{
	cin >> n;
	for(int i=1;i<=n;++i)
	{
		cin >> t[i] >> k[i];
		for(int j=1;j<=k[i];++j)
		{
			cin >> m;
			if(!c[m]) ++ans;
			++c[m];
			q.push(m);
		}
		while(t[in_]+86400<=t[i])
		{
			for(int j=1;j<=k[in_];++j)
			{
				--c[q.front()];
				if(!c[q.front()]) --ans;
				q.pop();
			}
			++in_;
		}
		cout << ans << endl;
	}
	return 0;
}
