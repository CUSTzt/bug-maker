// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, a, b;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        a+=s[i];
        if(s[i] != 'a')b+=s[i];
        if(a.size()+b.size()==n)break;
    }
    if(s == a+b)cout << a<<endl;
    else cout << ":(\n";
}