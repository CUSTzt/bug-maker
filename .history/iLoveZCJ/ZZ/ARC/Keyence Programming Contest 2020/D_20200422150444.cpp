/*const int N = 1200000;
 
vector<int> facs(N), invfacs(N);
 
void init()
{
    facs[0] = 1;
    for (int i = 1; i<N; i++) facs[i] = mul(facs[i-1], i);
    invfacs[N-1] = inv(facs[N-1]);
    for (int i = N-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}
 
int C(int n, int k)
{
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/