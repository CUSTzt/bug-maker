// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned ll
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
unsigned gcd(unsigned a,unsigned b) { return b?gcd(b,a%b):a;}
ull lcm(ull a, ull b){
    return a * b / gcd(a , b);
}
int n;
unsigned x, y , z;
unsigned tang(){
    unsigned t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    t = x;x=y;y=z;z=t^x^y;
    return z;
}
unsigned a[10000000+10];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _; cin >> _;
    for(int _cs = 1; _cs <= _; _cs++) {
        cin >> n >> x >> y >> z;
        ull ans = 0;
        for(int i = 0; i < n; i++){
            a[i] = tang();
        }
        int k = min(n , 100);
        nth_element(a, a+k, a+n, [&](auto a, auto b){return a > b;});
        for(int i = 0; i < k; i++){
            for(int j = i + 1; j < k; j++){
                ans = max(ans, lcm(a[i],a[j]));
            }
        }
        cout << "Case #" << _cs << ": " << ans << endl;
    }
    return 0;
}