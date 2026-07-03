#include <stdio.h>
#include <string.h>

int main (){
  int MSSV;
  char HO_TEN[50];
  float t,l,h,dtb;
  
  printf ("nhap MSSV: ");
  scanf ("%d", &MSSV);

   getchar();

  printf ("Nhap HO_TEN: ");
  fgets(HO_TEN , sizeof (HO_TEN),stdin);
  
  printf ("nhap toan li hoa: ");
  scanf ("%f %f %f", &t,&l,&h);
  dtb = (t*2+l+h)/4;

  printf ("MSSV la: %d\n",MSSV);
  printf ("HOTEN la:  %s", HO_TEN);
  printf ("DTB la: %.2f", dtb);

  return 0;
}