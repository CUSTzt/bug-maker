// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5+100;
int f[N][32],a[N],n , m;
void ST_prework(){
	for(int i = 1; i <= n;i++)
		f[i][0] = a[i];
	int t = log(n) / log(2) +1;
	for(int j = 1; j < t; j++)
		for(int i = 1; i <= n - (1<<j) +1; i++)
			f[i][j] = max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		//这个式子的意义就是 长度为2^j的子区间的最大值是左右两半长度为2^(j-1)
		//的子区间的最大值中的较大的一个
}

int ST_query(int l ,int r){
	int k = log(r-l+1) / log(2);
	return max(f[l][k], f[r-(1<<k)+1][k]);
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)scanf("%d",&a[i]);
    for(int i = 0;i < m; i++){
        int l , r;
        scanf("%d%d",&l,&r);
        printf("%d\n",)
    }
    return 0;
}