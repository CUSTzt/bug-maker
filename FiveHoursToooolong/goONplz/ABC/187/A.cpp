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
    string s;
    cin >> s;
    int tp = 0, tq = 0;
    for(auto i : s){
        tp+=i-'0';
    }
    cin >> s;
    for(auto i : s){
        tq+=i-'0';
    }
    cout << max(tp , tq);
    return 0;
}