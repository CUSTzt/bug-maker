#include<bits/stdc++.h>

using namespace std;
#define int long long 
int slove(int x){
    if(x <= 1)return x;
    int ans = 0;
    for(int l = 1, r; l <= n;l = r+1){
        r = n / (n/l);
        ans += (n/l)*(l+r)*(r-l+1)
    } 

}
int32_t main(){

}