 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-07-18 19:37:18
 # @Description: 打好acm就能和cls一样天天吃小龙虾
 ***********************************************/
//原题链接：http://poj.org/problem?id=3784
//动态维护中位数问题：依次读入一个整数序列，每当已经读入的整数个数为奇数时，输出已读入的整数构成的序列的中位数。
//#include <bits/stdc++.h>
//对顶堆的做法
/*
建立两个二叉堆，一个小根堆，一个大根堆。读入时设当前序列长度M,
维护：
1.序列中从小到大排名1~M/2 的数在大根堆
2.序列中从小到大排名M/2+1~M 的数在小根堆
当其中一个堆元素过多，则放入另一个堆
每次读入一个数X
If x < Small.top():
Big.push(x)
else:
small.push(x)
 */
#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
priority_queue <int>Big;//大根堆
priority_queue<int ,vector<int >,greater<int > >Small;//小根堆
void Push(int x)
{
	if(Small.empty()||x>Small.top())Small.push(x);
	else Big.push(x);
	if(Big.size()>Small.size()+1)Small.push(Big.top()),Big.pop();
	if(Small.size()>Big.size()+1)Big.push(Small.top()),Small.pop();
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		while(!Big.empty())Big.pop();
		while(!Small.empty())Small.pop();
		int m,n,tp;
		cin>>m>>n;
		cout<<m<<' '<<((n+1)>>1)<<'\n';
		for(int i=1;i<=n;i++){
			cin>>tp;
			Push(tp);
			if(i&1)cout<<(Small.size()>Big.size()?Small.top():Big.top())<<' ';
			if((i+1)%20==0&&i!=n)cout<<'\n';
		}
		cout<<'\n';
	}
	//exit(0);
}
//法二
//链表的离线做法
