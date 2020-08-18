// claris 最大团
#include<cstring>
#include<cstdio>
const int N = 100;
int n , i , j , k , max[N], f[N][N], g[N][N],ans;
int dfs(int cur , int tot){
    if(!cur){
        if(tot > ans) return ans = tot, 1;
        return 0;
    }
    for(int i = 0, j , u , nxt ; i < cur; i++){
        if(cur - i + tot <= ans) return 0;
        u = f[tot][i] , nxt = 0;
        if(max[u] + tot <= ans) return 0;
        for(j = i+1; j < cur; j++){
            if(g[u][f[tot][j]]) f[tot+1][nxt++] = f[tot][j];
        }
        if(dfs(nxt , tot+1)) return 1;
    }
    return 0;
}
int main(){
    while(scanf("%d",&n)){
        if(n == 0) break;
        memset(g, 0 , sizeof g), memset(f , 0 , sizeof f); ans = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
            scanf("%d",&g[i][j]);
        }
        for(i = n-1; ~i ; dfs(k,1),max[i--]=ans)for(k=0,j=i+1;j<n;j++)if(g[i][j])f[1][k++]=j;
        printf("%d\n",ans);
    }   
}