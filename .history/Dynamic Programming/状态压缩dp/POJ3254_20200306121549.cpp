// She is Pretty pretty!
//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 12;
const int mod = 100000000;
int n , m , dp[][], a[20][20],s[20],ok[];
bool check(int x){
    if(x&(x<<1))return false;
    return true;
}
void pre(){

}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            s[i] |= (a[i][j] << m-1-i);
        }
    }
    
    ll ans = 0;


    return 0;
}