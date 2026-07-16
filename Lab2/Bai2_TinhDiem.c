#include <stdio.h>

int main (){
    int t , l,h;
    float dtb;
    printf ("nhap diem toan: ");
    scanf ("%d",&t);
     printf ("nhap diem ly: ");
    scanf ("%d",&l);
    printf ("nhap diem hoa: ");
    scanf ("%d",&h);

     dtb =(float)(t*3  + l*2 +h)/6;
    printf ("diem trung binh la: %.2f",dtb);
}