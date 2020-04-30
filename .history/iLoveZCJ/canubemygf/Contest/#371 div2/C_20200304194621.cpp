// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;

int cnt(ll x){
    int res = 0;
    int pos = 1;
    while(x){
        if(x % 2)res+=pos;
        x/=10;
        pos*=2;
    }
    return res;
}
ll n , m , x;
char ch;
map<int , int > MP;
int main()
{
    cin >> n ;
    for(int i = 0; i < n ; i++){
        cin >> ch >> x;
        int y = cnt(x);
        
    }
    return 0;
}