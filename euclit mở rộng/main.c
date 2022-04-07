#include<stdio.h>
#include<conio.h>
#include<math.h>

void xuLy(int a, int b){
    int x2 = 1, x1 = 0, y2 = 0, y1 = 1;
    int q, r, x, y, d;
    if(b == 0){
        d = a;
        x = 1;
        y = 0;
        printf("\nd = %d\nx = %d\ny = %d", d, x, y);
        return;
    }
    while(b > 0){
        q = a / b;
        r = a - q * b;
        x = x2 - q * x1;
        y = y2 - q * y1;
        //
        a = b;
        b = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    d = a;
    printf("\nUoc chung lon nhat la: %d", d);
}

int main(){
    int a, b;
    printf("Nhap a: ");
    scanf("%d", &a);
    printf("\nNhap b: ");
    scanf("%d", &b);
    xuLy(a, b);
    getch();
    return 0;
}
