// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
ll f[N], ans, b[N], op , x , d[100], cnt, n; 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> op >> x;
        if(op <= 2){
            if(op == 1 && b[x]) continue;
            if(op == 2 && !b[x])
        }else {
            cout << ans << endl;
        }
    }
    return 0;
}