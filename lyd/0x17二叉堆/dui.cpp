void swap(int &x,int &y){int z=x;x=y;y=z;}
struct small_root_heap{
    int heap[M],top;
    void insert(int x){heap[++top]=x;int t=top;while(t>1&&heap[t]<heap[t>>1])swap(heap[t],heap[t>>1]),t>>=1;}
    void pop()
    {
        int t=2;
        heap[1]=heap[top];heap[top--]=0;
        while(t<=top)
        {
            if(heap[t]>heap[t+1]&&t<top)t++;
            if(heap[t]<heap[t>>1])swap(heap[t],heap[t>>1]),t<<=1;
            else break;
        }
    }
};
struct big_root_heap{
    int heap[M],top;
    void insert(int x){heap[++top]=x;int t=top;while(t>1&&heap[t]>heap[t>>1])swap(heap[t],heap[t>>1]),t>>=1;}
    void pop()
    {
        int t=2;
        heap[1]=heap[top];heap[top--]=0;
        while(t<=top)
        {
            if(heap[t]<heap[t+1]&&t<top)t++;
            if(heap[t]>heap[t>>1])swap(heap[t],heap[t>>1]),t<<=1;
            else break;
        }
    }
};

