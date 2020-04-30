// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
class segtree
{
public:
	#define s (1<<18)
	ll seg[s*2];
	ll lazy[s*2];
	void lazy_evaluate(int k)
	{
		if(k*2+2>=s*2) return ;
		lazy[k*2+2]+=lazy[k];
		lazy[k*2+1]+=lazy[k];
		seg[k*2+2]+=lazy[k];
		seg[k*2+1]+=lazy[k];
		lazy[k]=0;
	}
	ll update(int beg,int end,int idx,int lb,int ub,ll num)
	{
		if(ub<beg||end<lb)
		{
			return seg[idx];
		}
		if(beg<=lb&&ub<=end)
		{
			lazy[idx]+=num;
			seg[idx]+=num;
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx);
		}
		return seg[idx]=max(update(beg,end,idx*2+1,lb,(lb+ub)/2,num),update(beg,end,idx*2+2,(lb+ub)/2+1,ub,num));
	}
	ll query(int beg,int end,int idx,int lb,int ub)
	{
		if(ub<beg||end<lb)
		{
			return -1000000000000000000LL;
		}
		if(beg<=lb&&ub<=end)
		{
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx);
		}
		return max(query(beg,end,idx*2+1,lb,(lb+ub)/2),query(beg,end,idx*2+2,(lb+ub)/2+1,ub));
	}
}t
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}