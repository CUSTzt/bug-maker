// #include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1e4 + 5,M = 80;
int n,m;
char str[N][M];
bool st[M];
int nxt[N];
void cal_nxt() {
	nxt[1] = 0;
	for(int i = 2,j = 0;i <= n;i++) {
		while(j > 0 && strcmp(str[i],str[j + 1])) j = nxt[j];
		if(!strcmp(str[i],str[j + 1])) j++;
		nxt[i] = j;
	}
}
int main() {
//	freopen("in.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i++) {
		scanf("%s",str[i]);
		for(int j = 1;j <= m;j++) {
			if(!st[j]) {
				for(int k = j;k < m;k += j) {
					for(int t = 0;t < j;t++) {
						if(k + t < m && str[i][t] != str[i][k + t]) {
							st[j] = true;
							break;
						}
					}
					if(st[j]) break;
				}
			}
		}
	}
	int w;
	for(int i = 1;i <= m;i++) 
		if(!st[i]) {
			w = i;
			break;
		}
	//printf("%d\n",w);
	for(int i = 1;i <= n;i++) str[i][w] = '\0';
	cal_nxt();
	int h = n - nxt[n];
	printf("%d\n",w * h);
	return 0;
}
