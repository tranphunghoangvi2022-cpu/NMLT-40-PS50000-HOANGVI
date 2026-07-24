#include <stdio.h>
#include <math.h>

int main() {
    int chon;

    printf("+----------------------------------+\n");
    printf("|      MENU CHUONG TRINH LAB4      |\n");
    printf("+----------------------------------+\n");
    printf("| 1. Tinh trung binh chia het cho 2|\n");
    printf("| 2. Kiem tra so to                |\n");
    printf("| 3. Kiem tra so chinh phuong      |\n");
    printf("| 4. Thoat chuong trinh            |\n");
    printf("+----------------------------------+\n");
    printf("Chon tu 1 den 4: ");
    scanf("%d", &chon);
    
    switch(chon){
     case 1:
     printf ("ban da chon tinh tb chia het cho 2:\n");
     break;
     case 2:
     printf ("ban da chon kiem tra so nguyen to:\n");
     break;
     case 3:
     printf ("ban da chon ktra so chinh phuong: \n");
     break;
     case 4:
     printf ("thoat chuong trinh\n ");
     break;
     default:
     printf ("lua chon khong hop le ");
     break;
    }
    int min, max;
    if (chon == 1){
    printf ("nhap vao min va max: ");
    scanf ("%d %d",&min ,&max);
    if(min > max){
        printf ("nhap sai yeu cau");
    }
    else {
    int tong =0;
    int dem =0;
    for (int i =min ; i <= max; i++){
     if (i%2 ==0){
        tong += i;
        dem ++;
     }
    }
    if (dem >0){
        printf ("trung binh tong cac so chia het cho 2: %.2f",(float)tong/dem);
    }
    else {
        printf("ko co so chia het cho 2");
    }
    }
}
   int x;
   if (chon ==2 ){
printf("Nhap vao so can kiem tra: ");
scanf("%d", &x);

if (x < 2) {
    printf("Khong phai la so nguyen to");
} else {
    int nguyento = 1;

    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            nguyento = 0;
            break;
        }
    }

    if (nguyento)
        printf("La so nguyen to");
    else
        printf("Khong phai la so nguyen to");
}
}
if (chon == 3){
    int x;
    int chinhphuong;
    printf ("nhap vao so chinh phuong: ");
    scanf ("%d",&x);
    for (int i=1; i = sqrt(x); i++){
         if (i*i == x){
            printf ("la so chinh phuong");
            break;
         }
         else {
            printf ("ko la so chinh phuong ");
         }
    }
}
 }
