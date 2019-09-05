//把状态j按照除以Vi的余数分组
//余数为0———————— 0, Vi,2Vi……
//余数为1———————— 1, 1+Vi,1+2Vi……  
//··········
//余数为Vi-1——————(V-1),(Vi-1)+Vi,(Vi-1)+2Vi……

#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x)&(-x)
#define eps 1e-8
const int maxn = 1e6+10;
using namespace std;
int n , m;
int f[maxn];
int q[maxn];
int V[maxn],W[maxn],C[maxn];
int calc(int i , int u , int k){
	return f[u + k*V[i]] - k*W[i];
}
int main()
{
	cin>>n>>m;
	memset(f, 0xcf,sizeof(f));  // -inf
	f[0] = 0;
	for(int i = 1; i <= n;i++){
		cin>>V[i]>>W[i]>>C[i];
		//除以V[i]的余数
		for(int u = 0; u < V[i];u++){
			//建立单调队列
			int l = 1, r= 0;
			//把最初的候选集合插入队列
			int maxp = (m - u) / V[i];
			for(int k = maxp - 1; k >= max(maxp - C[i], 0);k--){
				while(l <= r && calc(i , u ,q[r]) <= calc(i , u , k))r--;
				q[++r] = k;
			}
			//倒序循环每个状态
			for(int p =maxp; p >= 0;p--){
				//排除过时决策
				while(l <= r&&q[l]>p-1)l++;
				if(l <= r){
					f[u+p*V[i]] = max(f[u+p*V[i]], calc(i,u,q[l])+p*W[i]);
				}
				//插入新决策， 同时维护队尾单调性
				if(p - C[i] - 1 >= 0){
					while(l <= r && calc (i,u,q[r]) <=calc(i,u,p-C[i]-1))r--;
					q[++r] = p - C[i] - 1;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= m;i++){
		ans = max(ans , f[i]);
	}
	cout << ans<<endl;
}

