
//此题以区间最大值为例
const int SIZE = 1e5+10;
struct SegmentTree{
	int l , r ;
	int dat;
}t[SIZE * 4];

//线段树的建树
void build(int p , int l , int r){
	t[p].l = l ,t[p].r = r;                    //节点p表示[l , r]
	if(l == r){t[p].dat = a[l];return ;}       //叶节点
	int mid = (l + r) / 2;                     //折半
	build(p*2, l , mid);                       //左子节点[l, mid] 编号p*2
	build(p*2+1, mid+1, r);                    //右子节点[mid+1,r] 编号p*2+1
	t[p].dat = max(t[p*2].dat, t[p*2+1].dat);  //从下往上传递信息
}

build(1,1,n); //调用入口

//线段树的单点修改   例如 一条“C   x   v”的指令， 把A[x]的值修改成v
//时间复杂度 O(log N)
void change(int p ,int x, int v){
	if(t[p].l == t[p].r){t[p].dat = v; return;} //找到叶节点
	int mid = (t[p].l + t[p].r) / 2;
	if(x <= mid)change(p*2 , x, v);
	else change(p*2+1 , )
}
