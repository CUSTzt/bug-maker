#include <bits/stdc++.h>

using namespace std;
deque<int >deq;
int n , ans , a[3000000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1; i <= n;i++){
		cin>>a[i];
		a[i+n] = a[i];
	}
	deq.push_back(1);
	for(int i = 1; i <= (n<<1);i++){
		while(deq.size()&&i - deq.front() > (n>>1))
			deq.pop_front();
		ans = max(ans , a[i]+a[deq.front()]+i-deq.front());
		while(deq.size()&&(a[i] - i >= a[deq.back()] - deq.back()))
			deq.pop_back();
		deq.push_back(i);
	}
	cout << ans<<endl;
}