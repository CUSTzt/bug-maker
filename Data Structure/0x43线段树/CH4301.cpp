#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x)&(-x)
#define eps 1e-8
const int maxn = 5e5+10;
using namespace std;
struct SegmentTree{
	int l , r, lmax, rmax, dat , sum;
}t[maxn*4];
int n , m, a[maxn];
void build(int p , int l , int r){
	t[p].l = l ,t[p].r = r;                    //节点p表示[l , r]
	if(l == r){t[p].dat=t[p].sum=t[p].lmax=t[p].rmax=a[l];return ;}       //叶节点
	int mid = (l + r) / 2;                     //折半
	build(p*2, l , mid);                       //左子节点[l, mid] 编号p*2
	build(p*2+1, mid+1, r);                    //右子节点[mid+1,r] 编号p*2+1
	t[p].sum=t[p<<1].sum+t[p*2+1].sum;
    t[p].lmax=max(t[p<<1].lmax,t[p<<1].sum+t[p*2+1].lmax);//本身,以及左边前缀和加上右边前缀最大子段和
    t[p].rmax=max(t[p*2+1].rmax,t[p*2+1].sum+t[p<<1].rmax);//本身,以及右边前缀和加上左边后缀最大子段和.
    t[p].dat=max(max(t[p<<1].dat,t[p*2+1].dat),t[p<<1].rmax+t[p*2+1].lmax);
}
void change(int p , int x , int v){
	if(t[p].l == t[p].r){
		t[p].dat = v;
		t[p].sum = v;
		t[p].lmax = v;
		t[p].rmax = v;
		return ;
	}
	int mid = (t[p].l + t[p].r) / 2;
	if(x <= mid)change(p*2 , x , v);
	else change(p*2+1, x, v);
	t[p].sum=t[p<<1].sum+t[p*2+1].sum;
    t[p].lmax=max(t[p<<1].lmax,t[p<<1].sum+t[p*2+1].lmax);//本身,以及左边前缀和加上右边前缀最大子段和
    t[p].rmax=max(t[p*2+1].rmax,t[p*2+1].sum+t[p<<1].rmax);//本身,以及右边前缀和加上左边后缀最大子段和.
    t[p].dat=max(max(t[p<<1].dat,t[p*2+1].dat),t[p<<1].rmax+t[p*2+1].lmax);
}
SegmentTree ask(int p , int l , int r){
	if(l <= t[p].l && r >= t[p].r)return t[p];  //完全包含
	int mid = (t[p].l + t[p].r) / 2;
	int val = -(1 << 30); //负无穷大
	SegmentTree a, b , c;
	a.dat = a.sum = a.lmax = a.rmax = val;
	b.dat = b.sum = b.lmax = b.rmax = val;
	c.sum = 0;
	if(l <= mid){
		a = ask(p*2, l , r);
		c.sum += a.sum;
	} 
	if(r > mid){
		b = ask(p*2+1, l , r);
		c.sum = b.sum;
	}
	c.dat = max(max(a.dat, b.dat),a.rmax+b.lmax);
	c.lmax = max(a.lmax,b.lmax+a.sum);
	if (l>mid)
        c.lmax=max(c.lmax,b.lmax);
    c.rmax=max(b.rmax,b.sum+a.rmax);
    if (r<=mid)
        c.rmax=max(c.rmax,a.rmax);
    return c;
}
int main()
{
	ios::sync_with_stdio(false );
	cin.tie(0);
	int n , m;
	cin >> n >> m;
	for(int i = 1; i <= n ;i++){
		cin >> a[i];
	}
	build(1, 1, n);
	for(int i = 0; i < m;i++){
		int k , x ,y;
		cin >> k >> x >> y;
		if(k == 1){
			if(x > y)
				swap(x, y);
			cout << ask(1, x, y).dat<<endl;
		}
		else change(1, x, y);
	}
}
