#include<bits/stdc++.h>
using namespace std;
const int maxn = 500;
int t,a[maxn],now,flag,vis[maxn],nowmax,nowmin;
char s[maxn];
int main(){
	cin >> t;
	while (t--){
		memset (a,0,sizeof (a));
		memset (vis,0,sizeof (vis));
		scanf ("%s",s+1);
		now=500;flag=0;nowmax=500;nowmin=500;
    	a[now]=s[1]-'a'+1;vis[s[1]-'a'+1]=1;
		for (register int i=2;i<=strlen(s+1);++i){
			int num=s[i]-'a'+1;
			nowmax=max(now,nowmax);
			nowmin=min(now,nowmin);
			if (!vis[num]){
				if (a[now+1]==0){
					++now;a[now]=num;vis[num]=1;
				}
				else{
					if (a[now-1]==0){
						--now;a[now]=num;vis[num]=1;
					}
					else{
						flag=1;break;
					}
				}
			}
			else{
				if (a[now-1]==num){
					--now;
				}
				else{
					if (a[now+1]==num){
						++now;
					}
					else{
						flag=1;break;
					}
				}
			}
		}
		nowmax=max(now,nowmax);
		nowmin=min(now,nowmin);
		if (flag) printf ("NO\n");
		else{
			printf ("YES\n");
			for (register int i=nowmin;i<=nowmax;++i){
				printf ("%c",a[i]+'a'-1);
			}
			for (register int i=1;i<=26;++i){
				if (!vis[i]) printf ("%c",i+'a'-1);
			}
			printf ("\n");
		}
	}
	return 0;
}
