namespace Dinic {
	const int MAXV = 2e6+100;
	const int MAXE = 3e6+100;
	struct Edge {
		int u, v, c, f;
		Edge(){}
		Edge( int u, int v, int c, int f ):
			u(u),v(v),c(c),f(f){}
	};
	int n, m, s, t;
	int head[MAXV], nxt[MAXE<<1];
	Edge edge[MAXE<<1];
	void init( int n2 ) {
		n = n2, m = 0;
		for( int i = 0; i < n; ++i ) head[i] = -1;
	}
	void adde( int u, int v, int c ) {
		edge[m] = Edge(u, v, c, 0);
		nxt[m] = head[u], head[u] = m++;
		edge[m] = Edge(v, u, 0, 0);
		nxt[m] = head[v], head[v] = m++;
	}
	int dis[MAXV], cur[MAXV];
	queue<int> q;
	bool bfs() {
		for( int i = 0; i < n; ++i ) dis[i] = 1e9;
		dis[s] = 0, q.push(s);
		while( !q.empty() ) {
			int u = q.front(); q.pop();
			for( int i = head[u]; ~i; i = nxt[i] ) {
				Edge &e = edge[i];
				if( e.c > e.f && dis[e.v] == 1e9 ) {
					dis[e.v] = dis[u] + 1;
					q.push(e.v);
				}
			}
		}
		return dis[t] != 1e9;
	}
	int dfs( int u, int res ) {
		if( u == t || !res ) return res;
		int flow = 0;
		for( int &i = cur[u]; ~i; i = nxt[i] ) {
			Edge &e = edge[i];
			if( e.c > e.f && dis[e.v] == dis[u] + 1 ) {
				int f = dfs(e.v, min(e.c-e.f, res));
				flow += f, res -= f;
				e.f += f, edge[i^1].f -= f;
				if( !res ) break;
			}
		}
		return flow;
	}
	int solve( int s2, int t2 ) {
		s = s2, t = t2;
		int flow = 0;
		while( bfs() ) {
			for( int i = 0; i < n; ++i ) cur[i] = head[i];
			flow += dfs(s, 1e9);
		}
		return flow;
	}
}