#include <stdio.h>
#include <math.h>

int main (){
    int chon;
    do
    {
        /* code */
    
    printf("--------------------\n");
    printf ("MENU CHUONG TRINH LAB 3\n");
    printf ("--------------------\n");
    printf("0.CHUC NANG TINH HOC LUC SINH VIEN: \n");
    printf ("1.CHUC NANG GIAI PHUONG TRINH BAC 2: \n");
    printf ("2.CHUC NANG TINH TIEN DIEN TIEU THU HANG THANG: \n");
    printf ("3.THOAT CHUONG TRinh ");
    printf ("------------------------------\n");
    printf ("CHON TU 0 DEN 3: ");
    scanf ("%d",&chon);
    switch (chon){
        case 0:
         printf("Ban da chon chuc nang: 0. Tinh hoc luc sinh vien.\n");
         break;
        case 1:
        printf("Ban da chon chuc nang: 1. Giai phuong trinh bac 2.\n");
        break;
        case 2:
        printf("Ban da chon chuc nang: 2. Tinh tien dien.\n");
        break;
        case 3:
        printf ("Ban chon chuc nang: 3. Thoat chuong trinh\n");
        break;
        default: 
        printf ("lua chon ko hop le! \n");
        break;
    }
    float  diem;
    if(chon ==0)
    { 
        printf ("Nhap vao hoc luc cua ban: \n");
        scanf ("%f",&diem);
        if (diem >=0 && diem <=10){
             if (diem>=9)
        {
            printf ("Hoc sinh xuat sac\n");
        }
        else if (diem>=8 && diem<9){
            printf ("Hoc sinh gioi\n");
        }
        else if (diem>=6.5 && diem <8){
            printf ("Hoc sinh kha\n");
        }
        else if (diem>=5 && diem <6.5){
            printf ("Hoc sinh trung binh\n");
        }
        else if (diem>=3.5 && diem <5){
            printf ("Hoc sinh yeu\n");
        }
        else {
            printf ("Hoc sinh kem\n");
        }
    }
    else {
        printf ("diem so khong hop le");
    }
}

   int a,b,c ;
   float x;
   if (chon == 1){
   printf ("nhap vao 3 he so a b c cho pt ax^2 +bx +c =0: ");
   scanf("%d %d %d",&a ,&b ,&c);
   if (a == 0) {
     if (b==0 && c==0){
    printf ("ptr vo so nghiem");
   }
   else if (b==0 && c!=0 ){
    printf ("ptrinh vo nghiem ");
   }
   else { 
    x= (float)-c/b;
    printf ("ptr co nghiem x la: %.2f",x);
     }
   }else {
    float delta;
    delta = b*b -4*a*c;
    if (delta <0){
        printf ("prinh vo nghiem ");
    }
    else if (delta ==0){
        x= -b /(2.0*a);
        printf ("ptr co nghiem kep:%.2f ",x);
    }
    else {
      float x1, x2;
        x1 = (-b + sqrt(delta))/(2.0*a);
        x2 = (-b - sqrt(delta))/(2.0*a);

        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
    }
   }
 }
 if (chon == 2)
{
    int kwh;
    float tien = 0;

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
            tien = kwh * 1678;
        }
        else if (kwh <= 100)
        {
            tien = 50 * 1678
                 + (kwh - 50) * 1734;
        }
        else if (kwh <= 200)
        {
            tien = 50 * 1678
                 + 50 * 1734
                 + (kwh - 100) * 2014;
        }
        else if (kwh <= 300)
        {
            tien = 50 * 1678
                 + 50 * 1734
                 + 100 * 2014
                 + (kwh - 200) * 2536;
        }
        else if (kwh <= 400)
        {
            tien = 50 * 1678
                 + 50 * 1734
                 + 100 * 2014
                 + 100 * 2536
                 + (kwh - 300) * 2834;
        }
        else
        {
            tien = 50 * 1678
                 + 50 * 1734
                 + 100 * 2014
                 + 100 * 2536
                 + 100 * 2834
                 + (kwh - 400) * 2927;
        }

        printf("Tong tien dien phai tra: %.0f dong\n", tien);
    }
}   
    } while (chon !=3);
    return 0;

}
