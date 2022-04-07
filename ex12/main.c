//Thuật toán kiểm tra Fermat
#include <stdio.h>
#include <stdlib.h>
int binary(int n, int a[]){
    int j=0;
    for(int i=n; n>0; n=n/2) {
        a[j] = n % 2;
        j++;
    }
    return j;
}
void inBin(int a[], int n){

    for(int j=n-1; j>=0; j--){
          printf("%d", a[j]);
        }
        printf("\n");
}
int nhanBinhPhuongLap(int a,int k,  int n ){
    int b, A;
    b=1;
    if(k==0){
        return b;
    }
    A=a;
    int arrK[100];
    int t=binary(k, arrK);
    if(arrK[0]==1){
        b=a;
    }
    for(int i=1; i<=t; i++){
        A=A*A %n;
        if(arrK[i]==1){
            b=A*b%n;
        }
    }
    return b;
}
int check(int n, int t, int a[]){
    for(int i=1; i<=t; i++){
        int r= nhanBinhPhuongLap(a[i-1], n-1, n);
            if(r!=1){
                return 0;
            }
    }
    return 1;
}
int main()
{
    int n, t;
    printf("Nhap vao so n: \n");
    scanf("%d", &n);
        printf("Nhap vao so t: \n");
    scanf("%d", &t);
    int a[t];
    for(int i=0; i<t; i++){
        printf("Nhap so a:\n");
        scanf("%d", &a[i]);
    }
    if(check(n, t, a)==1){
        printf("\n%d la so nguyen to", n);
    }
    else
                printf("\n%d la hop so", n);

}
