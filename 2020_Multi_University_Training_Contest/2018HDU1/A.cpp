#include<bits/stdc++.h>
using namespace std;

void up(int n){
    int mx = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-i; j++){
            for(int k = 1; k <= n-i-j; k++){
                if(i &&j&&k&&(n%i==0)&&(n%j==0)&&(n%k==0) && (i+j+k==n) ){
                    mx=max(mx, i*j*k );
                    // cout << i << "   " << j << " "
                }
            }
        }
    }
    cout << "n === " << n << "  mx == " << mx << endl;
}
int main(){
    // freopen("out.txt","w",stdout);
    // for(int i = 1; i <= 100; i++){
    //     up(i);
    // }
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int _;
    cin >> _;
    while(_--){
        int n; cin >> n;
        if(n % 3 == 0){
            long long tp = n / 3;
            long long ans = tp * tp * tp;
            cout <<  ans << endl;
            continue;
        }else if(n % 4 == 0){
            long long tp = n/4;
            long long ans = tp * tp *tp * 2ll;
            cout << ans << endl;
            continue;
        }else {
            cout << -1 << endl;
        }
    }

}