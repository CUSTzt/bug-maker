/*
设 dp[i][j] 表示 B 的前 i 个字符和 AL...AR 的某个前缀的公共子序列长度为 j 时，这个最短前缀的长度。

那么有 dp[i][j]=min{dp[i][j],dp[i−1][j]},
dp[i][j]=min{dp[i][j],Next[dp[i−1][j−1]][B[i]]}

因为 B 的长度只有20，所以对于每个询问，我们重新dp一次。
预处理出 Next 数组的时间复杂度为 O(26|A|), 每次dp的复杂度为 O(|B|2)，因此，对于 m 个询问，这道题的时间复杂度为 O(26|A|+m|B|2)。

*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

#define RG register int
#define LL long long

template<typename elemType>
inline void Read(elemType &T){
    elemType X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    T=(w?-X:X);
}

int Next[100010][26],dp[21][26];
char str[100010],pat[30];
int T,N,M,Q;

inline void Init(){
    memset(Next,0x3f,sizeof(Next));
    for(RG i=N;i>=1;--i){
        for(RG j=0;j<26;++j)
            Next[i-1][j]=Next[i][j];
        Next[i-1][str[i]-'a']=i;
    }
    return;
}

inline int Solve(int L,int R){
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=L-1;
    for(RG i=1;i<=M;++i){
        dp[i][0]=L-1;
        for(RG j=1;j<=i;++j){
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
            if(dp[i-1][j-1]<R)
                dp[i][j]=min(dp[i][j],Next[dp[i-1][j-1]][pat[i]-'a']);
        }
    }
    for(RG i=M;i>=0;--i)
        for(RG j=i;j<=M;++j)
            if(dp[j][i]<=R) return i;
    return 0;
}

int main(){
    Read(T);
    while(T--){
        scanf("%s",str+1);
        scanf("%s",pat+1);
        N=strlen(str+1);
        M=strlen(pat+1);
        Init();
        Read(Q);
        while(Q--){
            int L,R;
            Read(L);Read(R);
            printf("%d\n",R-L+1+M-(Solve(L,R)<<1));
        }
    }
    return 0;
}