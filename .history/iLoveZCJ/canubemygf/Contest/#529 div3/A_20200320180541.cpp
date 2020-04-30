// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int v[] ={1,3,6,10,15,21,28,36,45,55}; 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    int n;
    cin >> n;
    set<int >ts;
    for(int i = 0; i < 10;i++){
        ts.insert(v[i]);
    }
    for(int i = 0; i < n; i++){
        if(ts.count())cout << s[i];
    }
    return 0;
}