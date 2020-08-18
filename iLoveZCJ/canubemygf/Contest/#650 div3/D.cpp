#include<iostream>
using namespace std;
bool flag[502][502];//记录出队元素
char matrix[502][502];
int dx[4]={1,0,0,-1};//上下左右移动
int dy[4]={0,-1,1,0};
struct Point{
    int x,y,step;
} points[2502];//存放结果的队列
int main(){
    int n,k,startX,startY;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
            flag[i][j]=true;
            if(matrix[i][j]=='1'){
                startX=i;
                startY=j;
            }
        }
    }
    int ent=0,exp=0;//进队和出队的标志，将起点入队
    points[0].x=startX;
    points[0].y=startY;
    points[0].step=0;
    flag[startX][startY]=false;
    ent++;
    while(exp<=ent){
        Point p1=points[exp];
        Point p2;
        for(int i=0;i<4;i++){
            p2.x=p1.x+dx[i];
            p2.y=p1.y+dy[i];
            p2.step=p1.step+1;
            // cout << p2.x << "  " << p2.y << "  " << p2.step << endl;
            if(p2.x<0||p2.x>=n||p2.y<0||p2.y>=n||matrix[p2.x][p2.y]=='3'||!flag[p2.x][p2.y]) continue;
//            cout << p2.x << "  " << p2.y << "  " << p2.step << endl;
            if(matrix[p2.x][p2.y]=='2'){
                if(p2.step<=k){
                    // cout << p2.step << "   " << endl;
                    cout<<"Yes"<<endl;
                }
                else
                    cout<<"No"<<endl;
                return 0;
            }
            points[ent]=p2;
            flag[p2.x][p2.y]=false;
            ent++;
        }
        exp++;
    }
    cout<<"No"<<endl;
    return 0;
}