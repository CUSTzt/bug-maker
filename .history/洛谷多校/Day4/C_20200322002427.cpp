// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;

int n,k,line[N],best;

int main()
{
	
	cin >> n >> k;
	for (int i=0,x,g; i<n; i++)
	{
		cin >> g >> x;
		line[x]=g;
	}

	
	for (int i=0; i<N && i<=2*k; i++)
		best+=line[i];

	int cnt=best;
	// slide the interval on the number line
	for (int i=2*k+1; i<N; i++)
	{
		// slide the interval by 1
		cnt-=line[i-2*k-1];		// remove the first grass in the interval
		cnt+=line[i];			
		if (best<cnt) best=cnt;	
	}

	ofstream fout("lazy.out");
	out << best << endl;
}