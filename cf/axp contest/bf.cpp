#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<map>
#include<cstdio>
#include<stack>
using namespace std;
#define endl  '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int t, n, k, l, r;
ull m;
struct A
{
	ull a[110][110] = { 0 };
	void init()
	{
		for (int i = 1; i <= n; i++)
			a[i][i]=1;
	}
};

A mul(A a, A b)
{
	A re;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				re.a[i][j] = re.a[i][j] ^ (a.a[i][k] | b.a[k][j]);
	return re;
}

A mul1(A a, A b)
{
	A re;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
        {
			for (int k = 1; k <= n; k++)
            {
				re.a[i][j] = re.a[i][j] + a.a[i][k] * b.a[k][j];
                // cout<<i<<" "<<j<<" "<<k<<" "<<re.a[i][j]<<endl;
            }
        }
	return re;
}

A power(A a)
{
	A re;
	re.init();
	for (; m; m >>= 1)
	{
		if (m & 1)
			re = mul(re, a);
		a = mul(a, a);
	}
	return re;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k;
		A e, x, ans;
		for (int i = 1; i <= n; i++)
			cin >> x.a[i][1];
		e.init();
		while (k--)
		{
			cin >> l >> r;
            swap(e.a[l],e.a[r]);
		}
		ans = power(e);
		ans = mul1(ans, x);
		cout << ans.a[1][1];
		for (int i = 2; i <= n; i++)
			cout << " " << ans.a[i][1];
		cout << endl;
	}
	return 0;
}
