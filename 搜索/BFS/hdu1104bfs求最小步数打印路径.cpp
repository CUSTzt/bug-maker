 /****************************************************************
 # @Author:      miniLCT
 # @DateTime: 2019年10月20日 星期日 11时12分49秒
 # @Description: You build it. You run it 
 # @More: Once lots of AC, try Brute-force,dynamic programming 
 ****************************************************************/
#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;
struct Node
{
    int x;
    int step;
    queue<char> q;
};
int v[1000010];
int n,m,k;
bool bfs()
{
    int s=((n+1)%k+k)%k;
    queue<Node>q;
    Node now,next;
    now.x=n;now.step=0;
    q.push(now);
    memset(v,0,sizeof(v));
    while(!q.empty())
    {
        now=q.front();
        if((now.x%k+k)%k==s)
        {
            printf("%d\n",now.step);
            while(now.step--)
            {
                printf("%c",now.q.front());
                now.q.pop();
            }
            printf("\n");
            return true;
        }
        q.pop();
        int xx;
        xx=(now.x+m)%(k*m);
        if(!v[(xx%k+k)%k])
        {
            v[(xx%k+k)%k]=1;
            next=now;next.x=xx;next.q.push('+');next.step++;
            q.push(next);
        }
        xx=(now.x-m)%(k*m);
        if(!v[(xx%k+k)%k])
        {
             v[(xx%k+k)%k]=1;
            next=now;next.x=xx;next.q.push('-');next.step++;
            q.push(next);
        }
        xx=(now.x*m)%(k*m);//因为xx会变得很大 所以要求余变小
        if(!v[(xx%k+k)%k])
        {
            v[(xx%k+k)%k]=1;
            next=now;next.x=xx;next.q.push('*');next.step++;
            q.push(next);
        }
        xx=((now.x%m+m)%m)%(m*k);
        if(!v[(xx%k+k)%k])
        {v[(xx%k+k)%k]=1;
        next=now;next.x=xx;next.q.push('%');next.step++;
        q.push(next);
        }
    }
    return 0;
}
int main()
{

    while(scanf("%d%d%d",&n,&k,&m)!=EOF)
    {
        if(n==0&&k==0&&m==0)
            break;
        if(!bfs())
            printf("0\n");
    }
    return 0;
}
