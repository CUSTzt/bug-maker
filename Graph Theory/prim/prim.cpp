//prim 算法  类似与dijkstra算法   总是维护最小生成树的一部分
//prim 算法适用于稠密图，  kruskal算法适用于 稀疏图


//假设现在已经求得的生成树的顶点的集合是x

int cost [max_v][max_v];    //cost[u][v]表示边e=(u,v)的权值(不存在的时候设为inf)
int mincost[max_v];         //从集合x出发的边到每个顶点的最小权值
bool used[max_v];           //顶点i是否包含在集合x中
int V;                      //顶点数
int prim(){
	for(int i = 0; i < V; i++){
		mincost[i] = INF;
		used[i] = false;
	}
	mincost[0] = 0;
	int res = 0;
	while(true){
		int v = -1;
		//从不属于x的顶点中选取从x到其权值最小的顶点
		for(int u = 0; u < V; u++){
			if(!used[u] && (v == -1|| mincost[u] < mincost[v]))v = u;
		}
		if(v == -1 )break;
		used[v] = true; //把顶点v加入x
		res += mincost[v]; //把边的长度加到结果里
		for(int u = 0; u < V;u++){
			mincost[u] = min(mincost[u],cost[v][u]);
		}
	}
	return res;
}





















//prim 堆优化
// 在不确定有多少条边的时候不好用，建议还是用原始的prim算法
int N,M;//N个点，M个边
const int V_MAX = 100;
const int INF = 1<<31 - 1;
 
typedef struct edge
{
    int to, cost;
    edge(int a, int b){
        to = a;
        cost = b;
    }
}edge;
typedef pair<int ,int> P;
 
vector<edge > G[V_MAX];
int used[V_MAX];
 
int prim()
{
    int sum = 0;
    priority_queue<P, vector<P>, greater<P> > pque;
    pque.push(P(0,1));
 
    while(!pque.empty())
    {
        P temp = pque.top();
        pque.pop();
        int V = temp.second;
        int cos = temp.first;
        if(used[V])continue;
        sum += cos;
        used[V] = 1;
        for(int i=0; i<G[V].size(); i++)
        {
            edge e = G[V][i];
            pque.push(P(e.cost, e.to));
        }
    }
    return sum;
}
 
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0; i<M; i++)
    {
        int fir,sec,thi;
        scanf("%d%d%d",&fir, &sec, &thi);
        G[fir].push_back(edge(sec,thi));
        G[sec].push_back(edge(fir,thi));
    }
    cout << prim() << endl;
}
