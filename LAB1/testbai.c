#include <stdio.h>

int tong(int a, int b){
    return a+b;
}
int main(){
    int a,b;
   printf ("nhap a va b: ");
   scanf ("%d %d",&a,&b);
   printf ("Tong = %d",tong(a,b));

   return 0;
}
