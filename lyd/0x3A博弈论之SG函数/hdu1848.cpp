 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-07-16 10:36:58
 # @Description: 打好acm就能和cls一样天天吃小龙虾
 ***********************************************/
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int SG[maxn],S[maxn],Lim,N,f[maxn]={0,1};
int main()
{
	int m,n,p;
	for(int i=2;i<=25;i++)f[i]=f[i-1]+f[i-2];
		N=1005;
	for(int i=1;i<=N;i++){
		memset(S,0,sizeof(S));
		for(int j=1;j<=25&&f[j]<=i;j++)S[SG[i-f[j]]]=1;
			for(int j=0;j<=N;j++)if(!S[j]){SG[i]=j;break;}
		}
	while(cin>>m>>n>>p)
	{
		if(m==0&&n==0&&p==0)break;
		puts(SG[m]^SG[n]^SG[p]?"Fibo":"Nacci");
	}

}

/*
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
int SG[MAXN], S[MAXN], Lim, N, f[MAXN] = {0, 1};
int main() {
    for(int i = 2; i <= 20; i++) f[i] = f[i - 1] + f[i - 2];
    N = 1001;
    for(int i = 1; i <= N; i++) {
        memset(S, 0, sizeof(S));
        for(int j = 1; j <= 20 && f[j] <= i; j++) S[SG[i - f[j]]] = 1;
        for(int j = 0; j <= N; j++) if(!S[j]) {SG[i] = j; break;}
    }
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c)) {
        if(!a && !b && !c) break;
        puts(SG[a] ^ SG[b] ^ SG[c] ? "Fibo" : "Nacci");
    }
    return 0;
}*/