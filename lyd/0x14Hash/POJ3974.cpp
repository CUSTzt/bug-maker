//Author:XuHt
/*#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ull unsigned long long
using namespace std;
const int N = 1000006, P = 13331;
char s[N];
ull f1[N], f2[N], p[N];

ull H1(int i, int j) {
	return (f1[j] - f1[i - 1] * p[j - i + 1]);
}

ull H2(int i, int j) {
	return (f2[i] - f2[j + 1] * p[j - i + 1]);
}

int main() {
	int id = 0;
	p[0] = 1;
	for (int i = 1; i < N; i++) p[i] = p[i - 1] * P;
	while (scanf("%s", s + 1) && !(s[1] == 'E' && s[2] == 'N' && s[3] == 'D')) {
		++id;
		int ans = 0, len = strlen(s + 1);
		f2[len+1] = 0;
		for (int i = 1; i <= len; i++) f1[i] = f1[i - 1] * P + s[i];
		for (int i = len; i; i--) f2[i] = f2[i + 1] * P + s[i];
		for (int i = 1; i <= len; i++) {
			int l = 0, r = min(i - 1, len - i);
			while (l < r) {
				int mid = (l + r + 1) >> 1;
				if (H1(i - mid, i - 1) == H2(i + 1, i + mid)) l = mid;
				else r = mid - 1;
			}
			ans = max(l * 2 + 1, ans);
			l = 0, r = min(i - 1, len - i + 1);
			while (l < r) {
				int mid = (l + r + 1) >> 1;
				if (H1(i - mid, i - 1) == H2(i, i + mid - 1)) l = mid;
				else r = mid - 1;
			}
			ans = max(l * 2, ans);
		}
		printf("Case %d: %d\n", id, ans);
	}
	return 0;
}*/
//枚举中心位置  看能扩展出多长的回文串
//先O(N)预处理前缀Hash值   用O(1)计算任意子串的Hash值，类似的，倒着做一遍预处理，用O（1）计算任意子串倒着读的Hash值，对P,Q进行二分答案，从而在O(logN)时间内求出最大的 p和q，  
//奇 偶 回文子串计算 是不同的   
//O(Nlog(N))
//可用Manacher O(N)   板子题
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1100010;
char Ma[MAXN*2];
int Mp[MAXN*2];
void Manacher(char s[],int len ){
	int l=0;
	Ma[l++]='$';
	Ma[l++]='#';
	for(int i = 0;i < len;i++){
		Ma[l++] = s[i];
		Ma[l++] = '#';
	}
	Ma[l] = 0;
	int mx=0,id=0;
	for(int i = 0; i < l; i++){
		Mp[i] = mx > i? min(Mp [2*id-i],mx-i):1;
		while(Ma[i + Mp[i]] == Ma[i - Mp[i]])Mp[i]++;
		if(i+Mp[i]>mx){
			mx=i+Mp[i];
			id=i;
		}
	}
}
char s[MAXN];
int main()
{
	int id=0;
	while(scanf("%s",s)==1&&!(s[0]=='E'&&s[1]=='N'&&s[2]=='D')){
		++id;
		int len = strlen(s);
		Manacher(s,len);
		int ans=0;
		for(int i = 0;i < 2*len+2;i++)
			ans=max(ans,Mp[i]-1);
		printf("Case %d: %d\n",id , ans );
	}
}
