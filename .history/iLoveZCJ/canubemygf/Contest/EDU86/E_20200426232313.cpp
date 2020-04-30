int n , k ;
int a[N] , c[N] ;
vector<int> vec[N] ;
bool check(int x)
{
	rep(i , 0 , x - 1)  vec[i].clear();
	int now = 0 ;
	rep(i , 1 , n)
	{
		vec[now].pb(a[i]) ;
		now = (now + 1) % x ;
	}
	rep(i , 0 , x - 1)
	{
		int cnt = 0 ;
		for(auto u : vec[i])
		{
			cnt ++ ;
			if(cnt > c[u])  return 0 ;
		}
	}
	return 1 ;
}
signed main()
{
	ios;
	cin >> n >> k;
	rep(i , 1 , n) cin >> a[i] ; 
	rep(i , 1 , k) cin >> c[i] ;
	sort(a + 1 , a + n + 1 , greater<int>()) ;
	int l = 1 , r = n ;
	int ans = 1 ;
	while(l <= r)
	{
		int mid = (l + r) / 2 ;
		if(check(mid))  ans = mid , r = mid - 1 ;
		else  l = mid + 1 ;
	}
	rep(i , 0 , ans - 1)  vec[i].clear() ;
	int now = 0 ;
	rep(i , 1 , n)
	{
		vec[now].pb(a[i]) ;
		now = (now + 1) % ans ;
	}
	cout << ans << '\n';
	rep(i , 0 , ans - 1)
	{
		int siz = vec[i].size() ;
		cout << siz << " "; 
		for(auto u : vec[i])  cout << u << " ";
		cout << '\n';
	}
	return 0 ;
}
