using namespace std;
const int N = 3e5 + 10 , M = 200;
int n , a[N];
int vis[N] , cnt[N][220] , pos[N] , far[N] , last[N] , pre[N] ;
int st[N] , f[N];

signed main()
{
	int t;
	cin >> t;
	while(t --)
	{
		int ans = 1;
		cin >> n;
		rep(i , 1 , n) cin >> a[i];
		rep(i , 2 , M) pos[i] = cnt[0][i] = 0;
		rep(i , 1 , n)
		{
			rep(j , 1 , M) cnt[i][j] = cnt[i - 1][j];
			cnt[i][a[i]] ++ ;
		}
		rep(i , 1 , n) pre[i] = pos[a[i]] , pos[a[i]] = i;
		rep(i , 1 , M) pos[i] = far[i] = 0;
		per(i , n , 1) if(!pos[a[i]]) far[a[i]] = i , pos[a[i]] = i;
		rep(i , 1 , M) vis[i] = 0;
		rep(i , 1 , n)
		{
			if(!vis[a[i]]) f[i] = far[a[i]] , st[i]=1 , vis[a[i]] = 1;
			else f[i] = pre[f[last[a[i]]]] , st[i] = st[last[a[i]]] + 1;
			last[a[i]] = i;
			if(i < f[i])
			{
				int l = i + 1 , r = f[i] - 1 , ma = 0;
				rep(j , 1 , M) ma = max(ma , cnt[r][j] - cnt[l - 1][j]);
				ans = max(ans , (st[i] << 1) + ma);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
