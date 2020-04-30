#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6+100;
int n , k ,a[maxn], head, tail, p[maxn], q[maxn];
void get_max(){
	head = 1, tail = 0;
	for(int i = 1; i <= n; i++){
		while(head <= tail && q[tail] <= a[i])
			--tail;//从队尾出队
		q[++tail] = a[i];//入队
		p[tail] = i;//记录在原序列的位置
		while(p[head] <= i-k) // 长度不超过k
			head++;
		if(i >= k)cout << q[head] << ' ';
	}
	cout << endl;
}
void get_min(){
	head = 1, tail = 0;
	for(int i = 1; i <= n; i++){
		while(head <= tail && q[tail] >= a[i])
			--tail;///只要队列里有元素，并且尾元素比待处理值大，即表示尾元素已经不可能成为最小值，所以出队。直到尾元素小于待处理值，满足"单调"。
		q[++tail] = a[i];//入队
		p[tail] = i;//记录在原序列的位置
		while(p[head] <= i-k) // 长度不超过k
			head++;
		if(i >= k)cout << q[head] << ' ';
	}
	cout << endl;
}
int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	get_min();
	get_max();
}