//struct 表示链表的节点
//prev和next 两个指针指向前后相邻的两个节点，构成一个常见的双向链表结构
//为避免在左右两端或者空链表中访问越界，我们通常建立额外的两个节点head和tail代表链表头尾，
//把实际数据节点存储在head与tai之间
const int SIZE = 1050;
struct Node{
	int value;
	int prev, next;
}node[SIZE];
int head,tail,tot;

int initialize(){
	tot = 2;
	head = 1,tail = 2;
	node[head].next = tail;
	node[tail].prev = head;
}
int insert(int p , int val){
	q = ++tot;
	node[q].value = val;
	node[node[p].next].prev = q;
	node[q].next = node[p].next;
	node[p].next = q;
	node[q].prev = p;
}

void remove(int p){
	node[node[p].prev].next = node[p].next;
	node[node[p].next].prev = node[p].prev;
}
void clear(){//数组模拟链表清空
	memset(node, 0 , sizeof(node));
	head = tail = tot = 0;
}