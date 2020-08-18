#include<bits/stdc++.h>

using namespace std;
const int mod = 998244353;
const int N = 18;
int m , n;
int A[(1 << N) + 10], B[(1 << N) + 10], a[(1 << N) + 10], b[(1 << N) + 10];
void FWT(int *a , int n, int op){
    for(int d = 1; d < n; d <<= 1){
        for(int m = d<<1,i=0; i < n; i+=m){
            for(int j = 0; j < d; j++){
                int x = a[i+j], y = a[i+j+d];
                if(op == 1) a[i+j] = x+y , a[i+j+d] = x-y; // xor
                else if(op == 2)a[i+j] = x+y; // and
                else a[i+j+d] = x+y; // or
            }
        }
    }
}
void UFWT(int *a, int n , int op){
    for(int d = 1; d < n; d <<= 1){
        for(int m = d<<1,i=0; i < n; i+=m){
            for(int j = 0; j < d; j++){
                int x = a[i+j], y = a[i+j+d];
                if(op == 1) a[i+j] = (x+y)>>1 , a[i+j+d] = (x-y)>>1; // xor
                else if(op == 2)a[i+j] = x-y; // and
                else a[i+j+d] = y-x; // or
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> m;
    n = 1 << m;
    for(int i = 0; i < n; i++) cin >> A[i]
}