#include<bits/stdc++.h>
#define ios std::ios::sync_with_stdio(false)
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define int long long
using namespace std;
const int INF (0x3f3f3f3f3f3f3f3fll);
const int inf (0x3f3f3f3f);
const int N = 3e5 + 10;
struct Edge{
	int nex , to , w;
}edge[N << 1];
int head[N] , tot;
void add_edge(int u , int v , int w)
{
	edge[++ tot].nex = head[u];
	edge[tot].to = v;
	edge[tot].w = w;
	head[u] = tot;
} 

int n1 , n2 , n3;
int a[N] , b[N] , c[N];
int get(int t1 , int t2 , int t3)
{
	return (t1 - t2) * (t1 - t2) + (t1 - t3) * (t1 - t3) + (t2 - t3) * (t2 - t3);
}
int cal(int *a , int n1 , int *b , int n2 , int *c , int n3)
{
	int res = INF;
	rep(i , 1 , n1)
	{
		int one = lower_bound(b + 1 , b + 1 + n2 , a[i]) - b;
		int two = lower_bound(c + 1 , c + 1 + n3 , a[i]) - c;
		if(one > n2 || b[one] > a[i])
		{
			if(one>1) --one;
		}
		if(one <= n2 && two <= n3)
		{
			int t1 = a[i];
			int t2 = b[one];
			int t3 = c[two];
			res = min(res , get(t1 , t2 , t3));
		}
		one = lower_bound(c + 1 , c + 1 + n3 , a[i]) - c;
		two = lower_bound(b + 1 , b + 1 + n2 , a[i]) - b;

		if(one > n3 || c[one] > a[i])
		{
			if(one > 1) one -- ;
		}

		if(one <= n3 & two <= n2)
		{
			int t1 = a[i];
			int t2 = c[one];
			int t3 = b[two];
			res = min(res,get(t1 , t2 , t3));
		}
	}
	return res;
}
signed main()
{
	ios;
	cin.tie(0) , cout.tie(0);
	int t;
	cin >> t;
	while(t --)
	{
		int ans = INF;
		cin >> n1 >> n2 >> n3;
		rep(i , 1 , n1) cin >> a[i];
		rep(i , 1 , n2) cin >> b[i];
		rep(i , 1 , n3) cin >> c[i];
		sort(a + 1 , a + 1 + n1);
		sort(b + 1 , b + 1 + n2);
		sort(c + 1 , c + 1 + n3);
		ans = min(ans , cal(a , n1 , c , n3, b , n2));
		ans = min(ans , cal(c , n3 , a , n1,  b , n2));
		ans = min(ans , cal(b , n2 , a , n1, c , n3));
		cout << ans << '\n';
	}
	return 0;
}
