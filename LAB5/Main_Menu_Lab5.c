#include <stdio.h>
#include <stdbool.h>
#include <math.h>
void menu();
void chucnang1();
void chucnang2();
void chucnang3();
void chucnang4();
void checkTriangle(float a, float b, float c);
void hoanvi(int *a, int *b);
bool namnhuan(int a);
int max(int a, int b, int c);
int main()
{
    menu();
    int chon;
    printf("nhap 1 den 5: ");
    scanf("%d", &chon);

    switch (chon)
    {
    case 1:
        chucnang1();
        break;
    case 2:
        chucnang2();
        break;
    case 3:
        chucnang3();
        break;
    case 4:
        chucnang4();
        break;
    case 5:
        printf("Thoat chuong trinh!\n");
        break;
    default:
        printf("Lua chon khong hop le!\n");
    }
     return 0;
}

void menu()
{
    printf("+---------------------------------+\n");
    printf("|       MENU CHUONG TRINH LAP     |\n");
    printf("+---------------------------------+\n");
    printf("|1.Tim gia tri lon nhat trong 3 so|\n");
    printf("|2.Kiem tra nam nhuan             |\n");
    printf("|3.Hoan vi 2 so                   |\n");
    printf("|4.Kiem tra phan loai tam giac    |\n");
    printf("|5.Thoat chuong trinh             |\n");
}

void chucnang1()
{
    int a, b, c;
    printf("nhap a b c: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("so lon nhat: %d\n", max(a, b, c));
}
int max(int a, int b, int c)
{
    int lonnhat;
    lonnhat = a;
    if (b > lonnhat)
        lonnhat = b;
    if (c > lonnhat)
        lonnhat = c;
    return lonnhat;
}
void chucnang2()
{
    int a;
    printf("nhap nam de tinh: ");
    scanf("%d", &a);
    if (namnhuan(a))
    {
        printf("%d la nam nhuan", a);
    }
     else
    {
        printf("%d khong phai la nam nhuan\n", a);
    }
}
bool namnhuan(int a)
{
    if (a % 400 == 0 || (a % 4 == 0 && a % 100 != 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void chucnang3()
{
    int a, b;
    printf("nhap 2 so de doi: ");
    scanf("%d %d", &a, &b);
    hoanvi(&a, &b);
    printf("%d %d", a, b);
}
void hoanvi(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void chucnang4()
{
    float a, b, c;

    printf("Nhap 3 canh a b c: ");
    scanf("%f %f %f", &a, &b, &c);

    checkTriangle(a, b, c);
}
void checkTriangle(float a, float b, float c)
{
    if (a <= 0 || b <= 0 || c <= 0 ||
        a + b <= c || a + c <= b || b + c <= a)
    {

        printf("Day khong phai la 3 canh cua mot tam giac\n");
        return;
    }
    if (a == b && b == c)
    {
        printf("Day la tam giac deu\n");
    }
    else if ((a == b && fabs(a * a + b * b - c * c) < 0.0001) ||
             (a == c && fabs(a * a + c * c - b * b) < 0.0001) ||
             (b == c && fabs(b * b + c * c - a * a) < 0.0001))
    {

        printf("Day la tam giac vuong can\n");
    }
    else if (fabs(a * a + b * b - c * c) < 0.0001 ||
             fabs(a * a + c * c - b * b) < 0.0001 ||
             fabs(b * b + c * c - a * a) < 0.0001)
    {

        printf("Day la tam giac vuong\n");
    }
    else if (a == b || a == c || b == c)
    {
        printf("Day la tam giac can\n");
    }
    else
    {
        printf("Day la tam giac thuong\n");
    }
}
