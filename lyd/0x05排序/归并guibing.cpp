void marge(int l , int mid, int r){
	//合并a[l~mid]与a[mid+1~r]
	//a是待排序的数组，b是临时数组  cnt 是逆序对个数
	int i = l ,j = mid + 1;
	for(int k = l; k <= r; k++)
		if(j > r|| i <= mid && a[i] <= a[j])b[k] = a[i++];
	else b[k] =a[j++], cnt +=mid - i +1;

	for(int k = 1; k <= r; k++)a[k] = b[k];
}