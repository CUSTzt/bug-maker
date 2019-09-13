
// others
//数据规模很大  要用大数模拟  
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 10;
const int maxn = 2e3+30;
const int maxm = 1000;
const int c[] = {6,2,5,5,4,5,6,3,7,6};
int d[maxn][maxm],a[maxn];
int f[maxn][maxm];

void init(){
    int len;
    memset(d,0,sizeof(d));
    d[0][0] = 1;
    for (int i=0; i<=maxn-30; i++) {
       for (int j=0; j<10; j++) {
          if (!(i==0&&j==0) && i+c[j]<=maxn-30) {
              for (int k=0; k<maxm; k++) d[i+c[j]][k] += d[i][k];
              for (int k=0; k<maxm-1; k++) {
                 d[i+c[j]][k+1] += d[i+c[j]][k]/mod;
                 d[i+c[j]][k] %= mod;
              }
          }
       }
    }

    memset(f,0,sizeof(f));
    f[1][0] = d[1][0];
    for (int i=2; i<=maxn-30; i++) {
        for (int j=0; j<maxm; j++) f[i][j] = f[i-1][j] + d[i][j];
        for (int j=0; j<maxm-1; j++) {
            f[i][j+1] += f[i][j]/mod;
            f[i][j] %= mod;
        }
    }

    for (int i=6; i<=maxn-30; i++) {
        f[i][0]++;
        for (int j=0; j<maxm-1; j++) {
            f[i][j+1] += f[i][j]/mod;
            f[i][j] %= mod;
        }
    }

    for (int i=2; i<=maxn-30; i++) {
        len = maxm-1;
        while (f[i][len]==0) len--;
        a[i] = len;
    }
}

int n;
int main(){
    init();
    while (scanf("%d",&n)!=EOF){
       for (int i=a[n]; i>=0; i--) printf("%d",f[n][i]);
       printf("\n");
    }
    return 0;
}