#include <stdio.h>

int main (){
    int a,b;
    float x;
    printf ("nhap a va b: ");
    scanf("%d %d",&a,&b);
    x = -(float)(b/a);
    printf ("pt %dx +%d=0 x=%.1f",a,b,x);
}