#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define int long long
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
const int MOD = 110119;
const int M = MOD + 10;
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
LL invf[M], fac[M] = {1};
void fac_inv_init(LL n, LL p) { //调用fac_inv_init(MOD,MOD);
    FOR (i, 1, n)
        fac[i] = i * fac[i - 1] % p;
    invf[n - 1] = bin(fac[n - 1], p - 2, p);
    FORD (i, n - 2, -1)
        invf[i] = invf[i + 1] * (i + 1) % p;
}
inline LL C(LL n, LL m) { // n >= m >= 0
    return n < m || m < 0 ? 0 : fac[n] * invf[m] % MOD * invf[n - m] % MOD;
}
LL Lucas(LL n, LL m) { // m >= n >= 0
    return m ? C(n % MOD, m % MOD) * Lucas(n / MOD, m / MOD) % MOD : 1;
}
struct Point{
	int x, y;
}p[200];
bool cmp(Point a, Point b){
	return a.x < b.x;
}
int ncase,n , m , r, dp[200], x, y;
int32_t main(){
	memset(dp,0,sizeof dp);
	fac_inv_init(MOD,MOD);
	while(~scanf("%lld%lld%lld",&n,&m,&r)){
		n--,m--;
		int flag = 0;
		std::vector<Point> v;
		int cnt = 0;
		for(int i = 0; i < r; i++){
			scanf("%lld%lld",&x,&y);
			x--,y--;
			if(x == n && y == m)flag = 1;
			if((x+y)%3==0){
				p[cnt].x = x,p[cnt].y = y;
				v.push_back(p[cnt]);
				cnt++;
			}
		}
		if(flag || (n+m) % 3){printf ("Case #%I64d: %I64d\n",++ncase,0);;continue;}
		p[cnt].x=n,p[cnt].y=m;
		v.push_back(p[cnt]);
		cnt++;
		sort(v.begin(),v.end(),cmp);
		for(int i = 0; i < cnt;i++){
			int nn = (v[i].x+v[i].y) / 3;
			int mm = min(v[i].x,v[i].y) - nn;
			//printf("mm ==== %lld   nn === %lld\n",mm,nn );
			dp[i] = Lucas(nn , mm);
			dp[i] %= MOD;
			//printf("---dp[%lld] === %lld\n",i,dp[i] );

			for(int j = 0; j < i; j++){
				int xx = v[i].x - v[j].x;
				int yy = v[i].y - v[j].y;
				int nnn = (xx+yy) / 3;
				int mmm = xx - nnn;
				dp[i] -= (Lucas(nnn,mmm) * dp[j])%MOD;
				//printf("dp[%lld] === %lld\n",i,dp[i] );
				dp[i] = dp[i] + MOD;
				dp[i] %= MOD;
			} 
		}
		printf("Case #%I64d: %I64d\n",++ncase,dp[cnt-1]);
		//printf("Case #%lld: %lld\n",++ncase,dp[cnt-1]);	
	}
}