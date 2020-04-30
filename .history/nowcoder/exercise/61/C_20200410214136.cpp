#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")
using namespace std;
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb(X) push_back(X)
#define all(x) (x).begin(), (x).end()
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
typedef long long ll;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int, int> pii;
//ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
const int MAXN = 13;
int fa[MAXN], num[13], a, b, c ,d, m;
ll ans;
char temp[MAXN];
void init(int n)    //놓迦뺏
{
      for(int i=1;i<=n;i++)
       {
           fa[i]=i;
       }
}
int find(int x)
{
       if(fa[x]==x)
          return x;
        else
          return fa[x]=find(fa[x]);           //쨌쓺箕鍵
}
void unite(int x,int y)
{
		if (x > y) swap(x, y);
        x=find(x);
        y=find(y);
        if(x==y) return;
        	fa[y] = x;
}
bool same(int x,int y)
{
        return find(x)==find(y);
}
void dfs(int A, int B, int C, int D, int now) {
	if (now == 13) {
		//rep (i, 1, 13) cout << temp[i] ;
		//cout << '\n';
		rep (i, 1, 13) {
			if (temp[i] != temp[find(i)]) return;
		}
		++ans;
		return;
	}
	if (A) {
		temp[now] = 'A';
		dfs(A - 1, B, C, D, now + 1);
		temp[now] = 'E';
	}
	if (B)  {
			temp[now] = 'B';
			dfs(A, B - 1, C, D, now + 1);
			temp[now] = 'E';
	}
	if (C)  {
			temp[now] = 'C';
			dfs(A, B, C - 1, D, now + 1);
			temp[now] = 'E';
	}
	if (D){

			temp[now] = 'D';
			dfs(A, B, C, D - 1, now + 1);
			temp[now] = 'E'	;
	}
}
int main() {
	INIT
	init(12);
	cin >> a >> b >> c >> d >> m;
	while (m--) {
		int X, Y;
		cin >> X >> Y;
		unite(X, Y);
	}
	rep (i, 1, 13) find(i);
	rep (i, 1, 13) {
		//cout << i << ' ' << fa[i] << '\n';
		num[fa[i]]++;
		temp[i] = 'E';
	}
	dfs(a, b, c, d, 1);
	cout << ans;
	

	return 0;
}

