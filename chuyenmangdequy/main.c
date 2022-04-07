#include<stdio.h>
#include<conio.h>
#include<math.h>

int* chuyenMaTran(int a, int n[]){
    int w = 8, t=4;
    int k=( chuyenMaTran(a/(int)pow(2, w*t), n) )%(int)pow(2, w*t);
    return n;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
