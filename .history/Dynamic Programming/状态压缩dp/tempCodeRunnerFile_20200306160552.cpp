// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
bool check(int x){
    if(x & (x << 1))return false;
    return true;
}

int main()
{
    int p = 0;
    for(int i = 0; i < 1 << 21; i++){
        if(check(i))p++;
    }    
    return 0;
}