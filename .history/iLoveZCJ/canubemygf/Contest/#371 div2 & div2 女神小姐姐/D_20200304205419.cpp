#include<bits/stdc++.h>
using namespace std;
 
vector<int> a, s, t, S(4);
int n, k=0, i, R, l, r, m;
 
void bs()
{
	for (; l < r; )
	{
		m = (l + r) / 2;
		for (i = 0; i < 4; i++)
			S[i] = s[i] + t[i] * m;
		printf("? %d %d %d %d\n", S[0], S[1], S[2], S[3]);
		fflush(stdout);
		cin>>i;
		i -= k && a[0] >= S[0] & a[1] >= S[1] & a[2] <= S[2] & a[3] <= S[3];
		i ? R = r = m : l = m + 1;
	}
	for (i = 0; i < 4; i++)
		s[i] += t[i] * R;
}
 
int main()
{
cin>>n;
	for (; k < 2; k++)
	{
		s = { 1, 1, n, 1 }, t = { 0, 0, 0, 1 }, l=0, r=n, bs();
		s[1] = s[3], t = { 0, -1, 0, 0 }, l=0, r=s[1], bs();
		s[2] = 1, t = { 0, 0, 1, 0 }, l=0, r=n, bs();
		s[0] = s[2], t = { -1, 0, 0, 0 }, l=0, r=s[0], bs();
		a.insert(a.end(), s.begin(), s.end());
	}
	printf("! ");
	for (int i: a)
		printf("%d ", i);
}