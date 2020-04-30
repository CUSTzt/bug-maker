// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;


int n,k,line[MAXX],best;

int main()
{
	ifstream fin("lazy.in");
	fin >> n >> k;
	for (int i=0,x,g; i<n; i++)
	{
		fin >> g >> x;
		// mark the amount of the grass on the number line
		line[x]=g;
	}
	fin.close();

	// calculate the grass amount in the interval [0,2k]
	for (int i=0; i<MAXX && i<=2*k; i++)
		best+=line[i];

	int cnt=best;
	// slide the interval on the number line
	for (int i=2*k+1; i<MAXX; i++)
	{
		// slide the interval by 1
		cnt-=line[i-2*k-1];		// remove the first grass in the interval
		cnt+=line[i];			// add the grass in the next position
		if (best<cnt) best=cnt;	// update the best grass amount
	}

	ofstream fout("lazy.out");
	fout << best << endl;
	fout.close();
}