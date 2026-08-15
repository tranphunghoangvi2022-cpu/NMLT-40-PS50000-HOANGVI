#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


struct giaDien
{
    int muctieuthu;
    float gia;
};

struct SinhVien
{
    char hoTen[50];
    float diem;
};

struct PhanSo
{
    int tu;
    int mau;
};


void menu();
bool kiemtrasonguyen(float so);
bool kiemtrasont(int so);
bool kiemtrasochphuong(int so);
int timucln(int a, int b);
int timbcnt(int a, int b);
struct PhanSo rutGon(struct PhanSo ps);

void chucnang1();
void chucnang2();
void chucnang3();
void chucnang4();
void chucnang5();
void chucnang6();
void chucnang7();
void chucnang8();
void chucnang9();
void chucnang10();

int main()
{
    int chon;

    do
    {
        menu();
        printf(">> Chon chuc nang cua ban (0-10): ");
        scanf("%d", &chon);
        switch (chon)
        {
        case 0:
            printf("Tam biet!\n");
            break;

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
            chucnang5();
            break;

        case 6:
            chucnang6();
            break;

        case 7:
            chucnang7();
            break;

        case 8:
            chucnang8();
            break;

        case 9:
            chucnang9();
            break;

        case 10:
            chucnang10();
            break;

        default:
            printf("Nhap sai chuc nang, hay nhap tu 0 den 10\n");
            break;
        }
    } while (chon != 0);

    return 0;
}

void menu()
{
    printf("%-60s%s\n","|+---------------------------------------------------------+","|");
    printf("%-60s%s\n","|                         MENU CHUONG TRINH","|");
    printf("%-60s%s\n","+----------------------------------------------------------","+");
    printf("%-60s%s\n","| 1. Kiem tra so nguyen","|");
    printf("%-60s%s\n","| 2. Tim UCLN va BCNN cua hai so","|");
    printf("%-60s%s\n","| 3. Tinh tien quan Karaoke","|");
    printf("%-60s%s\n","| 4. Tinh tien dien","|");
    printf("%-60s%s\n","| 5. Doi tien","|");
    printf("%-60s%s\n","| 6. Tinh lai suat vay ngan hang","|");
    printf("%-60s%s\n","| 7. Chuong trinh vay tien mua xe","|");
    printf("%-60s%s\n","| 8. Sap xep thong tin sinh vien","|");
    printf("%-60s%s\n","| 9. Game FPOLY-LOTT0","|");
    printf("%-60s%s\n","| 10. Chuong trinh tinh toan phan so         ","|");
    printf("%-60s%s\n","| 0. Thoat chuong trinh            ","|");
    printf("%-60s%s\n","+---------------------------------------------------------","+");
    
}

bool kiemtrasonguyen(float so)
{
    return ((int)so == so);
}
bool kiemtrasont(int so)
{
    if (so < 2)
        return false;
    for (int i = 2; i * i <= so; i++)
    {
        if (so % i == 0)
            return false;
    }
    return true;
}

bool kiemtrasochphuong(int so)
{
    if (so < 0)
        return false;
    return kiemtrasonguyen(sqrt(so));
}

void chucnang1()
{
    float so;
    printf("Nhap so: ");
    scanf("%f", &so);
    if (kiemtrasonguyen(so))
    {
        printf("%.2f la so nguyen\n", so);
        if (kiemtrasont((int)so))
        {
            printf("%.2f la so nguyen to\n", so);
        }
        else
        {
            printf("%.2f khong phai la so nguyen to\n", so);
        }
        printf("%s\n", kiemtrasochphuong((int)so) ? "La so chinh phuong" : "Khong phai la so chinh phuong");
    }
    else
    {
        printf("%.2f khong phai la so nguyen\n", so);
    }
}

int timucln(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (b != 0)
    {
        int du = a % b;
        a = b;
        b = du;
    }
    return a;
}

int timbcnt(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    return (a * b) / timucln(a, b);
}

void chucnang2()
{
    int a, b;
    printf("Nhap a, b: ");
    scanf("%d%d", &a, &b);
    int ucln = timucln(a, b);
    int bcnn = timbcnt(a, b);
    printf("UCLN cua %d va %d la %d\n", a, b, ucln);
    printf("BCNN cua %d va %d la %d\n", a, b, bcnn);
}

void chucnang3()
{
    int giovao, giora, sogio;
    float tongtien;
    do
    {
        printf("Nhap gio vao va gio ra (12h-23h): ");
        scanf("%d%d", &giovao, &giora);
    } while ((giovao >= giora) || (giovao < 12) || (giora > 23));

    sogio = giora - giovao;
    if (sogio <= 3)
    {
        tongtien = sogio * 150000;
    }
    else
    {
        tongtien = 3 * 150000 + (sogio - 3) * 150000 * 0.7;
    }

    if (giovao >= 14 && giovao <= 17)
    {
        tongtien *= 0.9;
    }

    printf("Tong tien karaoke tu %d gio den %d gio la %.0f vnd\n", giovao, giora, tongtien);
}

void chucnang4()
{
    struct giaDien BangGiaDien[6] = {
        {50, 1678},
        {100, 1734},
        {200, 2014},
        {300, 2536},
        {400, 2834},
        {401, 2927}};
    int soKW;
    int tongtien = 0;

    printf("Nhap so kw tieu thu: ");
    scanf("%d", &soKW);
    if (soKW <= BangGiaDien[0].muctieuthu)
    {
        tongtien = soKW * BangGiaDien[0].gia;
    }
    else if (soKW <= BangGiaDien[1].muctieuthu)
    {
        tongtien = 50 * BangGiaDien[0].gia + (soKW - 50) * BangGiaDien[1].gia;
    }
    else if (soKW <= BangGiaDien[2].muctieuthu)
    {
        tongtien = 50 * BangGiaDien[0].gia + 50 * BangGiaDien[1].gia + (soKW - 100) * BangGiaDien[2].gia;
    }
    else if (soKW <= BangGiaDien[3].muctieuthu)
    {
        tongtien = 50 * BangGiaDien[0].gia + 50 * BangGiaDien[1].gia + 100 * BangGiaDien[2].gia + (soKW - 200) * BangGiaDien[3].gia;
    }
    else if (soKW <= BangGiaDien[4].muctieuthu)
    {
        tongtien = 50 * BangGiaDien[0].gia + 50 * BangGiaDien[1].gia + 100 * BangGiaDien[2].gia + 100 * BangGiaDien[3].gia + (soKW - 300) * BangGiaDien[4].gia;
    }
    else
    {
        tongtien = 50 * BangGiaDien[0].gia + 50 * BangGiaDien[1].gia + 100 * BangGiaDien[2].gia + 100 * BangGiaDien[3].gia + 100 * BangGiaDien[4].gia + (soKW - 400) * BangGiaDien[5].gia;
    }

    printf("Tong tien tieu thu %d kw la %d vnd\n", soKW, tongtien);
}

void chucnang5()
{
    struct loaitiente
    {
        int soluongto;
        int menhGia;
    };
    struct loaitiente dstiente[] = {
        {0, 1000},
        {0, 2000},
        {0, 5000},
        {0, 10000},
        {0, 20000},
        {0, 50000},
        {0, 100000},
        {0, 200000},
        {0, 500000}};

    int sopt = 9;
    int sotien;
    printf("Nhap so tien: ");
    scanf("%d", &sotien);

    int temp = sotien;
    for (int i = sopt - 1; i >= 0; i--)
    {
        dstiente[i].soluongto = temp / dstiente[i].menhGia;
        temp = temp % dstiente[i].menhGia;
        if (temp == 0)
            break;
    }

    for (int i = sopt - 1; i >= 0; i--)
    {
        if (dstiente[i].soluongto > 0)
        {
            printf("Menh gia: %6d | So to: %d\n", dstiente[i].menhGia, dstiente[i].soluongto);
        }
    }
}

void chucnang6()
{
    int tienvay = 12000000, kyhan = 12;
    float laithang = 0.05;
    int gocphaitra = tienvay / kyhan;

    printf("%-8s %-12s %-15s %-15s %-15s\n", "Thang", "Tien lai", "Goc phai tra", "Tien phai tra", "Con lai");
    for (int i = 1; i <= kyhan; i++)
    {
        int tienlai = tienvay * laithang;
        tienvay = tienvay - gocphaitra;
        printf("%-8d %-12d %-15d %-15d %-15d\n", i, tienlai, gocphaitra, tienlai + gocphaitra, tienvay);
    }
}

void chucnang7()
{
    double giaXe;
    printf("Nhap gia tri xe (VND): ");
    scanf("%lf", &giaXe);

    double phanTramVay = 0.8;
    double tienVay = giaXe * phanTramVay;
    double tienTraTruoc = giaXe * (1.0 - phanTramVay);
    int nam = 24;
    int thang = nam * 12;
    double laiSuatNam = 0.072;
    double laiSuatThang = laiSuatNam / 12;

    double gocHangThang = tienVay / thang;
    double laiThangDau = tienVay * laiSuatThang;
    double tienTraLanDau = tienTraTruoc + gocHangThang + laiThangDau;

    printf("\n--- THONG TIN VAY MUA XE ---\n");
    printf("Gia tri xe: %.0lf VND\n", giaXe);
    printf("So tien tra truoc (20%%): %.0lf VND\n", tienTraTruoc);
    printf("So tien vay (80%%): %.0lf VND\n", tienVay);
    printf("Thoi han vay: %d nam (%d thang)\n", nam, thang);
    printf("Tien goc tra hang thang: %.0lf VND\n", gocHangThang);
    printf("Tien lai thang dau tien: %.0lf VND\n", laiThangDau);
    printf("Tong so tien phai tra lan dau: %.0lf VND\n", tienTraLanDau);
}

void chucnang8()
{
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    struct SinhVien sv[100];
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        printf("Ho va ten: ");
        fflush(stdin);
        getchar(); // Đọc ký tự thừa
        fgets(sv[i].hoTen, sizeof(sv[i].hoTen), stdin);
        sv[i].hoTen[strcspn(sv[i].hoTen, "\n")] = 0;

        printf("Diem: ");
        scanf("%f", &sv[i].diem);
    }

    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (sv[i].diem < sv[j].diem)
            {
                struct SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }

 
    printf("\n%-25s %-10s %-15s\n", "Ho va Ten", "Diem", "Hoc Luc");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        char hocLuc[20];
        if (sv[i].diem >= 9) strcpy(hocLuc, "Xuat sac");
        else if (sv[i].diem >= 8) strcpy(hocLuc, "Gioi");
        else if (sv[i].diem >= 6.5) strcpy(hocLuc, "Kha");
        else if (sv[i].diem >= 5) strcpy(hocLuc, "Trung binh");
        else strcpy(hocLuc, "Yeu");

        printf("%-25s %-10.2f %-15s\n", sv[i].hoTen, sv[i].diem, hocLuc);
    }
}

void chucnang9()
{
    srand(time(NULL));
    int r1 = rand() % 15 + 1, r2 = rand() % 15 + 1;
    do
    {
        r2 = rand() % 15 + 1;
    } while (r1 == r2);

    int a, b;
    printf("Nhap hai so a va b (1-15): ");
    scanf("%d%d", &a, &b);

    int dem = 0;
    if ((a == r1) || (a == r2))
        dem++;
    if ((b == r1) || (b == r2))
        dem++;

    switch (dem)
    {
    case 0:
        printf("Chuc ban may man lan sau\n");
        break;
    case 1:
        printf("Chuc mung ban da dat giai nhi\n");
        break;
    case 2:
        printf("Chuc mung ban da dat giai nhat\n");
        break;
    }
    printf("Ket qua xo so: %d - %d\n", r1, r2);
}

struct PhanSo rutGon(struct PhanSo ps)
{
    int u = timucln(ps.tu, ps.mau);
    ps.tu /= u;
    ps.mau /= u;
    if (ps.mau < 0)
    {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
    return ps;
}

void chucnang10()
{
    struct PhanSo ps1, ps2, tong, hieu, tich, thuong;

    printf("Nhap phan so 1 (tu mau): ");
    scanf("%d%d", &ps1.tu, &ps1.mau);
    while (ps1.mau == 0)
    {
        printf("Mau so phai khac 0. Nhap lai mau so 1: ");
        scanf("%d", &ps1.mau);
    }

    printf("Nhap phan so 2 (tu mau): ");
    scanf("%d%d", &ps2.tu, &ps2.mau);
    while (ps2.mau == 0)
    {
        printf("Mau so phai khac 0. Nhap lai mau so 2: ");
        scanf("%d", &ps2.mau);
    }

    tong.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    tong.mau = ps1.mau * ps2.mau;
    tong = rutGon(tong);

    hieu.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    hieu.mau = ps1.mau * ps2.mau;
    hieu = rutGon(hieu);

    tich.tu = ps1.tu * ps2.tu;
    tich.mau = ps1.mau * ps2.mau;
    tich = rutGon(tich);

    printf("Ket qua phep tinh phan so\n");
    printf("Tong   : %d/%d\n", tong.tu, tong.mau);
    printf("Hieu   : %d/%d\n", hieu.tu, hieu.mau);
    printf("Tich   : %d/%d\n", tich.tu, tich.mau);
    if (ps2.tu == 0)
    {
        printf("Thuong : Khong the chia cho 0\n");
    }
    else
    {
        thuong.tu = ps1.tu * ps2.mau;
        thuong.mau = ps1.mau * ps2.tu;
        thuong = rutGon(thuong);
        printf("Thuong : %d/%d\n", thuong.tu, thuong.mau);
    }

}