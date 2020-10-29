// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n , m , x;
    char op[10];
    int tp1 = 0 , tp2 = (1 << 30) - 1, ans = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> op >> x;
        if(op[0] == 'O'){
            tp1 |= x, tp2 |= x; 
        }else if(op[0] == 'X'){
            tp1 ^= x, tp2 ^= x;
        }else {
            tp1 &= x, tp2 &= x;
        }
    }
    int now = 0;
    for(int i = 29; i >= 0; i--){
        if((tp1 >> i & 1) >= (tp2 >> i & 1)){
            ans |= (tp1 >> i & 1) << i;
        }else if((now | 1 << i) <= m){
            ans |= 1 << i, ans |= 1 << i;
        }
    }
    cout << ans << endl;
    return 0;
}