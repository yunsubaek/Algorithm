#include <stdio.h>
template<typename T>
void _swap(T &a,T &b){
    T t=a;
    a=b;
    b=t;
}
template<typename It, typename Comp>
void _sort(It begin,It end,Comp comp){
    if(begin==end)
        return;
    _swap(*begin,*((end-begin)/2+begin));
    It le = begin +1;
    It ri = end -1;
    It pivot = begin;
    while (le<=ri) {
		while(le <= ri&&!comp(*pivot,*le))
			le++;
		while (le <= ri&&!comp(*ri,*pivot))
			ri--;
		if (le <= ri) 
			_swap(*le, *ri);
	}
	_swap(*pivot, *ri);
	_sort(begin, ri,comp);
	_sort(ri + 1, end,comp);
}
bool cmp(const int &a,const int &b){
    return a<b;
}
int n;
int arr[1000000];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    _sort(arr,arr+n,cmp);
    for(int i=0;i<n;i++)
        printf("%d\n",arr[i]);
    return 0;
}
