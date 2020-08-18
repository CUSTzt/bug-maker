#include<bits/stdc++.h>
using namespace std;
#define MAXV 1000//这里应该根据题目自定

vector<int> G[MAXV];  //图 
int V;                       //顶点数 
int color[MAXV];  //顶点的颜色 （1 or -1） 


//顶点v，颜色c 
bool dfs(int v,int c){
    color[v] = c;
    //把当前顶点相邻的顶点扫一遍 
    for(int i = 0;i < G[v].size(); i++){
        //如果相邻顶点已经被染成同色了,说明不是二分图 
        if(color[G[v][i]] == c) return false;
        //如果相邻顶点没有被染色,染成-c,看相邻顶点是否满足要求 
        if(color[G[v][i]] == 0 && !dfs(G[v][i],-c)) return false;
    }
    //如果都没问题，说明当前顶点能访问到的顶点可以形成二分图 
    return true;
}

void solve(){
    //可能是不连通图，所以每个顶点都要dfs一次 
    for(int i = 0;i < V; i++){
        if(color[i] == 0){
            //第一个点颜色为 1 
            if(!dfs(i,1)){
                cout << "No" << endl;
                return;
            }
        }
    }
}
