#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#
using namespace std;
const int N=2000010;
unordered_map<int, int> mp;//用来存下离散化后的编号
int p[N];//并查集
int idx;//已经离散化个数
struct Query
{
    int x, y, e;
}query[N];
int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
int get(int x){//如果没有出现过x，那么就分配一个空间给x，idx++
    if(!mp.count(x))mp[x]=idx++;
    return mp[x];
}
int main(){
    int t;
    cin >> t;
    while(t--){
        idx=0;
        mp.clear();
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            int x,y,e;
            cin >> x >> y >> e;
            query[i]={get(x),get(y),e};
        }
        for(int i=0;i<idx;i++)p[i]=i;
        for(int i=0;i<n;i++){//先将所有相等的条件遍历，来更新并查集
            if(query[i].e){
                int pa=find(query[i].x);
                int pb=find(query[i].y);
                p[pa]=pb;
            }
        }
        bool flag=true;
        for(int i=0;i<n;i++){
            if(!query[i].e){
                int pa=find(query[i].x);
                int pb=find(query[i].y);
                if(pa==pb){
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}

