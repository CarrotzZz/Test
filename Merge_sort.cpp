# include "iostream"
using namespace std;

const int N = 20;
int tmp[N];
void merge_sort(int q[],int l,int r){
    if(l >= r) return;

    int mid = (l + r) >> 1;

    merge_sort(q, l, mid);
    merge_sort(q, mid  +1 ,r);

    int k = 0, i = l, j  = mid + 1;
    while(i <= mid && j <= r) {
        if (q[i] < q[j]){
            tmp[k++] = q[i++];
        }else {
            tmp[k++] = q[j++];
        }
    }
    while(i <= mid) {
        tmp[k++] = q[i++];
    }
    while(j <= r) {
        tmp[k++] = q[j++];
    }
    
    

    for(i = l, j = 0; i <= r; i++,j++) {
        q[i] = tmp[j];
    }
}

int main(){
    int a[] = {3,4,2,6,7};
    int n = sizeof(a)/sizeof(int);
    
    merge_sort(a,0,n - 1);
    for(int i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
    return 0;
}
/*
归并排序——分治
    还需要一个相等大小的数组空间，不推荐使用
1、确定分界点 mid / (l + r)
2、递归排序 left、right
3、归并->合二唯一
*/
