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
    int n = s.size();
    int pos = -1;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == 'a'){
            pos = i;
            break;
        }
    }
    string s1 = s.substr(0,pos+1);
    return 0;
}