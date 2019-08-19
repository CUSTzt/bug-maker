//复杂度 O(n) 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e7+10;
int v[maxn],prime[maxn];
int m;
void primes(int n){
	memset (v , 0 ,sizeof(v));  //最小质因子
	m = 0;//质数数量
	for(int i = 2; i <= n; i++){
		if(v[i] == 0){
			v[i] = i;prime[++m] = i;  //i是质数
		}
		//给当前的数i乘上一个质因子
		 for(int j = 1; j <= m;j++){
		 	//i有比prime[j]更小的质因子或者超出了n的范围，停止循环
		 	if(prime[j] > v[i] || prime[j] > n/i)break;
		 	//prime[j] 是合数 i*prime[j]的最小质因子
		 	v[i*prime[j]] = prime [j];
		 }
	}
	for(int i = 1; i <= m;i++)cout<<prime[i]<<endl;
}
int main(){
	primes(maxn);
}

/*
using namespace std;
const int N=1e6+10;
long long p[N],vis[N],n,m;
long long zs(long long n)//素数筛
{
    for(long long i=2;i<=n;i++)
    {
        if (!vis[i])
            p[++p[0]]=i;
        for(long long j=2;j<=n/i;j++)
            vis[i*j]=1;
    }
}
 */