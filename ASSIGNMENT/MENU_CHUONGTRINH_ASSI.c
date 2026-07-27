#include <Stdio.h>

int main (){
    int chon;
    int a,b;
    printf ("+----------------------------------------+\n");
    printf ("+             MENU QUAN LY               +\n");
    printf ("+----------------------------------------+\n");
    printf ("1.Kiem tra so nguyen                     +\n");
    printf ("2.Tim uoc va boi chung                   +\n");
    printf ("3.Chuong trinh tinh tien cho quan karaoke+\n");
    printf ("4.Tinh tien dien                         +\n");
    printf ("5.Tinh lai suat ngan hang vay tra gop    +\n");
    printf ("6.Sap xep thong tin sinh vien            +\n");
    printf ("7.tinh toan phan so                      +\n");
    printf("Chon tu 1 den 7: ");
    scanf("%d", &chon);
    switch(chon){
     case 1:
     printf ("ban chon ktra so nguyen\n");
    break;
     case 2 :
     printf ("ban chon tim uoc va boi chung\n");
     break;
     case 3:
     printf ("ban chon chuong trinh tinh tien karaoke \n");
     break;
     case 4:
     printf ("ban chon tinh tien dien \n");
     break;
     case 5:
     printf ("ban chon tinh lai suat \n");
     break;
     case 6:
     printf ("ban chon sap xep thong tin sinh vien \n");
     break;
     case 7:
     printf ("ban chon tinh toan phan \n");
     break;
    }
    
    int  n;
    if (chon ==1){
    printf ("nhap vao so nguyen: ");
    scanf("%d",&n);
    if (n>0){
        printf ("la so nguyen duong ");
    }
    else if(n<0) {
        printf ("la so nguyen am ");
    }
    else {
        printf("la so 0");
    }
    return 0;
}
    int min; 
    if (chon==2){
        printf ("nhap vao 2 so nguyen: ");
        scanf ("%d %d",&a,&b);
      if (a<b){
        min =a;
      }
      else {
        min =b;
      }
      printf ("uoc chung cua %d va %d la: ",a,b);
      for (int i=1; i<=min;i++){
           if (a%i == 0 && b%i ==0){
            printf ("%d, ",i);
         } 
      }
     

      printf ("\nboi chung cua %d va %d la: ",a,b);
      for (int k=1;k<=100;k++){
        if (k%a==0 && k%b==0){
            printf ("%d ",k);
        }
      }
      printf("...");
      return 0;
    }
    
    if(chon == 3){
        int tien, tg,c;
        printf ("nhap gio vao: ");
        scanf ("%d",&a);
        printf ("nhap gio ra: ");
        scanf ("%d",&b);
   if (b < 18) {
    tien = (b - a) * 60;
}
else if (a >= 18) {
    tien = (b - a) * 150;
}
else {
    tien = (18 - a) * 60 + (b - 18) * 150;
}
      printf ("so tien can tinh la %d.000 dong",tien);
    }
   
    if (chon == 4)
{
    int kwh;
    float tiendien = 0;

    printf("Nhap so kWh dien tieu thu: ");
    scanf("%d", &kwh);

    if (kwh < 0)
    {
        printf("So kWh khong hop le!\n");
    }
    else
    {
        if (kwh <= 50)
        {
            tiendien = kwh * 1678;
        }
        else if (kwh <= 100)
        {
            tiendien = 50 * 1678
                 + (kwh - 50) * 1734;
        }
        else if (kwh <= 200)
        {
            tiendien = 50 * 1678
                 + 50 * 1734
                 + (kwh - 100) * 2014;
        }
        else if (kwh <= 300)
        {
            tiendien = 50 * 1678
                 + 50 * 1734
                 + 100 * 2014
                 + (kwh - 200) * 2536;
        }
        else if (kwh <= 400)
        {
            tiendien = 50 * 1678
                 + 50 * 1734
                 + 100 * 2014
                 + 100 * 2536
                 + (kwh - 300) * 2834;
        }
        else
        {
            tiendien = 50 * 1678
                 + 50 * 1734
                 + 100 * 2014
                 + 100 * 2536
                 + 100 * 2834
                 + (kwh - 400) * 2927;
        }

        printf("Tong tien dien phai tra: %.0f dong\n", tiendien);
    }
}
if (chon == 5){
    int tienvay, thang;
float laixuat;

printf("Nhap tien muon vay: ");
scanf("%d", &tienvay);

printf("Nhap lai suat nam (%%): ");
scanf("%f", &laixuat);

printf("Nhap tra gop may thang: ");
scanf("%d", &thang);
float goc = (float)tienvay / thang;
float duNo = tienvay;
float lai, tongTra;

for (int i = 1; i <= thang; i++) {
    lai = duNo * (laixuat / 100) / 12;
    tongTra = goc + lai;

    printf("Thang %2d: Goc = %.0f, Lai = %.0f, Tong tra = %.0f\n",
           i, goc, lai, tongTra);

    duNo -= goc;
}
}
}
