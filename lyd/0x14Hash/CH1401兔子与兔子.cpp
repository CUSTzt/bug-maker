 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-07-21 22:48:49
 # @Description: 打好acm就能和cls一样天天吃小龙虾
 ***********************************************/
/*#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef unsigned long long ull;
const int maxn = 1e6+10;
char s[maxn];
ull f[maxn],p[maxn];

int main()
{
	scanf("%s", s+1);
	int n = strlen (s+1);
	int q;
	cin >> q;
	p[0] = 1; //131^0
	for(int i = 1;i <= n; i++){
		f[i] = f[i-1] *131 + (s[i] -'a' + 1);
		p[i] = p[i-1] *131; //131^i 
	}
	for(int i = 1; i <= q; i++)
	{
		int l1,r1,l2,r2;
		scanf("%d%d%d%d", &l1 , &r1 ,&l2 , &r2);
		if(f[r1] - f[l1-1] * p[r1 - l1 + 1] == f[r2] - f[l2 - 1] * p[r2 -l2 +1]){
			puts("Yes");
		}
		else {
			puts("NO");
		}
	}
}*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000010]; 
unsigned long long f[1000010], p[1000010];
int main() {
	scanf("%s", s + 1);
	int n, q;
	n = strlen(s + 1);
	cin >> q;
	p[0] = 1; // 131^0
	for (int i = 1; i <= n; i++) {
		f[i] = f[i-1] * 131 + (s[i]-'a'+1); // hash of 1~i
		p[i] = p[i-1] * 131; // 131^i
	}
	for (int i = 1; i <= q; i++) {
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		if (f[r1] - f[l1-1] * p[r1-l1+1] == // hash of l1~r1
			f[r2] - f[l2-1] * p[r2-l2+1]) { // hash of l2~r2
			puts("Yes");
		} else {
			puts("No");
		}
	}
}