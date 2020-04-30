// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
using namespace std;
const int MAXN = 1009, INF = 32700;
int n, m;
short A[MAXN][MAXN];
short B[MAXN][MAXN];
 
short dp(int i, int j)
{
	if(B[i][j] != -INF) return B[i][j];
	if(j == m) return B[i][j] = A[i][j];
 	int ti = i, tj = j;
	if(ti > 1) ti--;
	if(tj < m) tj++;
	return B[i][j] = min(A[i][j], dp(ti, tj));
}
 
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			scanf("%hd", &A[i][j]);
			B[i][j] = -INF;
		}
			
	for(int i = n-1; i >= 1; --i)
		for(int j = 1; j <= m; ++j)
			if(A[i][j] > A[i+1][j]) 
				A[i][j] = A[i+1][j];
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			dp(i, j);
	
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j < m; ++j)
			printf("%hd ", B[i][j]);
		printf("%hd\n", B[i][m]);
	}
	return 0;	
}