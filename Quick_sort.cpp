# include "iostream"
using namespace std;

void quick_sort(int q[],int l,int r){
    if(l >= r) return;

    int x = q[l], i = l - 1, j = r + 1;

    while(i < j){
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if(i < j) swap(q[i],q[j]);

        quick_sort(q, l, j);
        quick_sort(q, j + 1, r);
    }
}

int main(){
    int a[5] = {3,4,2,6,7};
    int n = sizeof(a)/sizeof(int);

    quick_sort(a,0,n - 1);
    for(int i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
}
