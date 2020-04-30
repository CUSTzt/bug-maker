#include<bits/stdc++.h>

using namespace std;
#define int long long 
int slove(int n){
    if(n <= 1)return n;
    int ans = 0;
    for(int l = 1, r; l <= n;l = r+1){
        r = n / (n/l);
        ans += (n/l)*(l+r)*(r-l+1)/2;
    } return ans;
}
int32_t main(){
    int a, b;
    cin >> a >> b;
    cout << (slove(a) - slove(b-1)) <<endl;
}