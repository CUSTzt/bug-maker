 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-09-10 20:50:30
 # @Description: You build it.You run it
 ***********************************************/
//    给定长度为N(N<1e5)的数列A,然后输入Q行(Q<1e5)操作指令
//题意:第一类指令"C l r d" 表示把数列中第l~r个数加上d
//    第二类指令"Q l r" 表示询问数列中第l~r个数的和
//线段树 的每个节点保存了 sum(区间和) add(增量延迟标记) 两个值 
//spread函数实现了延迟标记的向下传递
//延迟标记的含义为"该节点曾经被修改,但其子节点尚未被更新"  延迟标记 标识的是 子节点等待更新的情况
// 一个节点被打上"延迟标记"的同时  它自身保存的信息应该已经被修改完毕     

//一定要注意"更新标记"  和  "打标记" 之间的关系
//#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int n , m , l, r, d, a[maxn];
struct SegmentTree{
	int l , r;
	ll sum , add;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum    // 区间和
	#define add(x) tree[x].add    // 增量延迟标记
}tree[maxn*4];

void build(int p , int l , int r){
	l(p) = l ,r(p) = r;                    
	if(l == r){sum(p) = a[l];return ;}       
	int mid = (l + r) / 2;                     
	build(p*2, l , mid);                       
	build(p*2+1, mid+1, r);                   
	sum(p) = sum(p*2)+sum(p*2+1);
}
//延迟标记向下传递
void spread(int p){
	if(add(p)){   //节点p有标记
		sum(p*2) += add(p)*(r(p*2)-l(p*2)+1);  //更新左子节点信息
		sum(p*2+1) += add(p)*(r(p*2+1)-l(p*2+1)+1); //更新右子节点信息
		add(p*2) += add(p);  //给左子节点打延迟标记
		add(p*2+1) += add(p);  //给右子节点打延迟标记
		add(p) = 0;//清除p的标记
	}
}

void change(int p , int l , int r, int d){
	if(l <= l(p) && r >= r(p)){ // 完全覆盖
		sum(p) += (ll ) d*(r(p)-l(p)+1);//更新节点信息
		add(p) += d;
		return ; 
	}
	spread(p);   //下传延迟标记
	int mid = (l(p) + r(p)) / 2;
	if(l <= mid)change(p*2, l , r, d);
	if(r > mid)change(p*2+1, l , r, d);
	sum(p) = sum(p*2) + sum(p*2+1);
}
ll ask(int p , int l , int r){
	if(l <= l(p) && r >= r(p)) return sum(p);
	spread(p);  //下传延迟标记
    int mid=(l(p) + r(p))/2;
	ll val=0;
    if(l<=mid) val +=ask(p*2,l,r);
    if(r>mid) val +=ask(p*2+1,l,r);
    return val;
}

int main()
{
	close;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	while(m--){
		char ch;
		cin >> ch >> l >> r;
		if(ch == 'C'){
		    cin >> d;
		    change(1, l , r, d);
	    }
	    else cout << ask(1, l , r)<<endl;
	}
}

/******************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*******************************************************/