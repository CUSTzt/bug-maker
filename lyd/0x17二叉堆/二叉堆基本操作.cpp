//小根堆：树中的任意一个节点的权值都大于等于其父节点的权值
//大根堆：树中的任意一个节点的权值都小于等于其父节点的权值
从1开始编号， 左子节点编号是父节点编号x2，右子节点编号是父节点编号x2+1
//STL 中的priority_queue（优先队列） 为实现一个大根堆，支持push，top，pop
//不支持remove。

现在开始讨论大根堆，
Insert  插入值  O（logN）
int heap[maxn],n;
void up(){
	//向上调整
	while(p > 1){
		if(heap[p] > heap[p/2]){ //子节点大于父亲节点，不满足大根堆的性质
			swap(heap[p] , heap[p/2]);
			p /= 2;
		}
		else break;
	}
}
void Insert (int val ){
	heap[++n] = val;
	up(n);
}

GetTop   返回二叉堆堆顶权值，即最大值heap[1],复杂度为O(1)
int GetTop(){
	return heap[1];
}

Extract 把堆顶从二叉堆中移除 
把堆顶heap[1]和存储在数组末尾的节点heap[n]交换，然后移除数组末尾节点(令n减小1)
最后把堆顶通过交换的方式向下调整，直至满足堆性质。
O(logN)

void down(int p){
	int s = p * 2;//p的左子节点
	while(s <= n){
		if(s < n&& heap[s] < heap[s+1])s++;  //左右子节点中取较大者
		if(heap[s] > heap[p]){ // 子节点大于父节点，不满足大根堆性质
			swap(heap[s], heap[p]);
			p = s, s = p * 2;
		}
		else break;
	}
}
void Extract(){
	heap[1] = heap[n--];
	down(1);
}

Remove O(log N )
Remove(p) 操作把存在数组下标为p位置的节点从二叉堆中删除  
把heap[n]与heap[p]交换，然后令n减小1，注意此时heap[p]既可能向下调整，也有可能
向上调整，需要分别检查和处理。

void Remove(int k){
	heap[k] = heap[n--];
	up(k),down(k);
}