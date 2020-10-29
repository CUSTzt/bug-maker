#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
char a[1000010];
int Next[1000010], n, T;
void calc_Next() {
	Next[1] = 0;
	for (int i = 2, j = 0; i <= n; i++) {
		while (j > 0 && a[i] != a[j+1]) j = Next[j];
		if (a[i] == a[j+1]) j++;
		Next[i] = j;
	}
}
int main() {
	while (cin >> n && n) {
		scanf("%s", a + 1);
		calc_Next();
		printf("Test case #%d\n", ++T);
		for (int i = 2; i <= n; i++) {
			if (i % (i - Next[i]) == 0 && i / (i - Next[i]) > 1)
				printf("%d %d\n", i, i / (i - Next[i]));
		}
		puts("");
	}
}