#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb(X) push_back(X)
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
typedef long long ll;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int, int> pii;
//ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
const int MAXN = 1e6 + 15;

class SegmentTree {
	#define lson (p << 1)
	#define rson (p << 1 | 1)
	#define mid (l + r >> 1)
	private:
		int size;
		struct _SegmentTree {
			long long sum = 0,
					  lazy = 0;
		};
		_SegmentTree *s = NULL;
		
		void _push_up(int p) {
			s[p].sum = s[lson].sum + s[rson].sum;
		}
		
		void _push_down(int p, int l, int r) {
			if (s[p].lazy) {
				s[lson].sum += s[p].lazy * (mid - l + 1);
				s[rson].sum += s[p].lazy * (r - mid);
				s[lson].lazy += s[p].lazy;
				s[rson].lazy += s[p].lazy;
				s[p].lazy = 0;
			}
		}
		
		void _build(int p, int l, int r, long long a[]) {
			if (l == r) {
				s[p].sum = a[l];
				return;
			}
			_build(lson, l, mid , a);
			_build(rson, mid + 1, r, a);
			_push_up(p);
		}
		
		void _add(int p, int l, int r, int L, int R, long long c) {
			if (L <= l && r <= R) {
				s[p].sum += (r - l + 1) * c;
				s[p].lazy += c;
				return;
			}
			_push_down(p, l, r);
			if (L <= mid) _add(lson, l, mid, L, R, c);
			if (mid < R) _add(rson, mid + 1, r, L, R, c);
			_push_up(p);
		}
		
		long long _query(int p, int l, int r, int L, int R) {
			if (L <= l && r <= R) {
				return s[p].sum;
			}
			_push_down(p, l, r);
			long long Re = 0;
			if (L <= mid) Re += _query(lson, l, mid, L, R);
			if (mid < R) Re += _query(rson, mid + 1, r, L, R);
			return Re;
		}
		
	public:
		void add(int L, int R, int c) {
			_add(1, 1, size, L, R, c);
		}
		
		long long query(int L, int R) {
			return _query(1, 1, size, L, R);
		}
		
		SegmentTree(int _size, long long a[]) {
			size = _size;
			s = new _SegmentTree[size << 2];
			_build(1, 1, size, a);
		}
		#undef lson
		#undef rson
		#undef mid
};
SegmentTree *seg = NULL;

struct Edge;

struct Node {
	Edge *head = NULL;
	Node *fa = NULL;
	//	 *link_top = NULL,
	//	 *heavy_son = NULL;
	int dep = 0,
		value = 0,
		dfn = 0,
		size = 0;
}node[MAXN];

struct Edge {
	Edge *next = NULL;
	Node *to = NULL;
	
	Edge (Node *u, Node *v) {
		next = u -> head;
		u -> head = this;
		to = v;
	}
};

long long Dfn_array[MAXN];

void DFS1(Node *u) {
	u -> size = 1;
	for (Edge *e = u -> head; e != NULL; e = e -> next) {
		if (e -> to != u -> fa) {
			e -> to -> fa = u;
			e -> to -> dep = u -> dep + 1;
			DFS1(e -> to);
			u -> size += e -> to -> size;
		//	if (u -> heavy_son == NULL || e -> to -> size > u -> heavy_son -> size) {
		//		u -> heavy_son = e -> to;
		//	}
		}
	}
}

void DFS2(Node *u) {
	static int DFN = 0;
	Dfn_array[u -> dfn = ++ DFN] = u -> value;
	for (Edge *e = u -> head; e != NULL; e = e -> next)
		if (e -> to != u -> fa) //&& e -> to != u -> heavy_son)
			DFS2(e -> to);
}
void addroad(Node *x, Node *y, long long z) {
	if (x -> dfn > y -> dfn)
		swap(x, y);
	seg -> add(x -> dfn, y ->dfn, z);
}



long long querysubtree(Node *x) {
	return seg -> query(x -> dfn, x -> dfn + x -> size - 1);
}

int main() {
	INIT
	int N, M, R;
	cin >> N >> M >> R;
	rep (i, 1, N + 1) {
		cin >> node[i].value;
	}
	rep (i, 1, N) {
		int a, b;
		cin >> a >> b;
		new Edge(&node[a], &node[b]);
		new Edge(&node[b], &node[a]);
	}
	DFS1(&node[R]);
	DFS2(&node[R]);
	seg = new SegmentTree(N, Dfn_array);
	for (long long i = 1; i <= M; ++i) {
		int c, x, y;
		cin >> c >> x;
		switch(c) {
			case 1:
				cin >> y;
				addroad(&node[x], &node[x], y);
				break;
			case 2:
				cout << querysubtree(&node[x])<< '\n';
				break;
		}
	}

	return 0;
}

