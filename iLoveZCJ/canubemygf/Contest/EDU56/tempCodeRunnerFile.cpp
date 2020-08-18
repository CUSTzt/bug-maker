#include<bits/stdc++.h>

using namespace std;
const int maxn = 1000;
struct node{
	int start , end, id;
}a[maxn];
int cmp(node a , node b){ // 排序规则，结束时间为第一关键字，开始时间为第二关键字。
	if(a.end == b.end)return a.start < b.start;
	return a.end < b.end;
}
int main(){
	int n;
	cout << "请输入活动的数量n:" << endl;
	cin >> n;
	cout << "接下来 " << n << " 行，每行两个数，分别表示他们的开始时间和结束时间。"<< endl;
	for(int i = 1; i <= n; i++){
		cin >> a[i].start >> a[i].end;
		a[i].id = i;
	}
	sort(a+1, a+n+1, cmp);
	int j = 1;
	std::vector<node> v; // 用动态数组记录哪些被选。
	for(int i = 2; i <= n; i++){
		if(a[i].start >= a[j].end){
			v.push_back(a[i]); // 表示可以被选的，压入动态数组v中，记录一下
			j = i;
		}
	}
	cout << "一共可以安排" << v.size() << "个活动。" << endl;
	cout << "这些活动分别的编号分别是:" << endl;
	for(auto it : v){
		cout << it.id << " ";
	}
}

/*
数据：
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
*/