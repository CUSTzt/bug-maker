#include <bits/stdc++.h>
using namespace std;
int main(){
	int t ;
	cin >> t;
	while(t--){
		int n ;
		cin >> n;
		while(n % 2 == 0)n/=2;
		while(n % 5 == 0)n/=5;
		if(n == 1)cout << "No" << endl;
		else cout << "Yes" <<endl;
	}
}