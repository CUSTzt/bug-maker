// deque 形式
/*
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define pf push_front
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
deque<int >max_deque , min_deque;
int n , k, a[maxn] , s_min[maxn] , s_max[maxn];
//s_max  s_min 存储的是a的下标
int main()
{
	close;
	cin >> n >> k ;
	for(int i = 1; i <= n ;i++)
		cin >> a[i];
	min_deque.pf(1);
	max_deque.pf(1);
	s_min[1] = 1;
	s_max[1] = 1;
	k--;
	for(int i = 2; i <= n; i++){
		while(min_deque.size() && min_deque.front() + k < i)
			min_deque.ppf();
		while(max_deque.size() && max_deque.front() + k < i)
			max_deque.ppf();
		while(min_deque.size() && a[min_deque.back()] >= a[i])
			min_deque.ppb();
		while(max_deque.size() && a[max_deque.back()] <= a[i])
			max_deque.ppb();
		min_deque.pb(i);
		max_deque.pb(i);
		s_min[i] = min_deque.front();
		s_max[i] = max_deque.front();
	}
	for(int i = k+1; i <= n;i++)
		cout << a[s_min[i]]<<' ';
	cout << endl;
	for(int i = k+1; i <= n;i++)
		cout << a[s_max[i]]<<" ";
	cout << endl;
}
*/
#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6+100;
int n , k ,a[maxn], head, tail, p[maxn], q[maxn];
void get_max(){
    memset(p, 0, sizeof p);
    memset(q, 0, sizeof p);
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
    memset(p, 0, sizeof p);
    memset(q, 0, sizeof p);
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