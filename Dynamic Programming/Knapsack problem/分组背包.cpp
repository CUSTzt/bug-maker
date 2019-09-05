

//注意i ， j ， k 三个的 顺序，要满足条件的  每一组最多一个。  阶段   状态    决策   三个的关系搞清楚
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
const int maxn = 105;
int N , V;
int s[maxn],v[maxn][maxn],w[maxn][maxn];
int f[maxn];
int main(){
	cin>>N>>V;
	for(int i = 1; i <= N;i++){
		cin>>s[i];
		for(int j = 1; j <= s[i];j++){
			cin>>v[i][j]>>w[i][j];
		}
	}
	memset(f, 0xcf,sizeof(f));
	f[0] = 0;
	for(int i =1; i <= N;i++)
		for(int j = V;j >= 0;j--)
			for(int k = 1; k <= s[i];k++)
				if(j >= v[i][k])
					f[j] = max(f[j],f[j - v[i][k]]+w[i][k]);


				cout << f[V]<<endl;
}