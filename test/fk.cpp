int c[N] , aa[N];
signed main()
{
	ios;
	init();
	cin.tie(0) , cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --)
	{
		int n , l , k;
		cin >> n >> l >> k;
		rep(i , 1 , n) cin >> c[i];
		sort(c + 1 , c + 1 + n);
		int ma = 0 , mi = 0;
		int pos = n - k + 2;
		rep(i , l - 1 , n - 1)
		{
			if( i % l + k < l) ma += c[pos];
			else ma += c[-- pos];
		}
		int ne = l - k + 1;
		pos = ne - 1;
		rep(i , l - 1 , n - 1)
		{
			if(i % l + ne < l) mi += c[pos];
			else mi += c[++ pos];
		}
		cout << ma << " " << mi << '\n';
	}
	return 0;
}
