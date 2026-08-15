#include <stdio.h>
#include <string.h>
#include <ctype.h>
struct SinhVien
{
    char mssv[50];
    char tenSV[50];
    char nganhHoc[50];
    float diemTB;
};
void menu();
void chucNang1(struct SinhVien ds[], int *n);
void chucNang2(struct SinhVien ds[], int n);
void chucNang3(struct SinhVien ds[], int n);
void chucNang4(struct SinhVien ds[], int n);

int main()
{
    struct SinhVien danhSach[100];
    int n = 0;
    int chon;

    do
    {
        menu();
        printf("Ban hay chon chuc nang tu (1-5): ");

        if (scanf("%d", &chon) != 1)
        {
            chon = 0;
        }
        while (getchar() != '\n')
            ;

        switch (chon)
        {
        case 1:

            chucNang1(danhSach, &n);
            break;
        case 2:
            chucNang2(danhSach, n);
            break;
        case 3:
            chucNang3(danhSach, n);
            break;
        case 4:
            chucNang4(danhSach, n);
            break;
        case 5:
            printf("Ban da thoat chuong trinh\n");
            break;
        default:
            printf("Ban phai chon chuc nang tu 1 - 5\n");
            break;
        }
    } while (chon != 5);

    return 0;
}

void menu()
{
    printf("\n+---------------------------------------------------+\n");
    printf("|             HE THONG QUAN LY SINH VIEN            |\n");
    printf("+---------------------------------------------------+\n");
    printf("| 1. Nhap va xuat danh sach sinh vien               |\n");
    printf("| 2. Sap xep sinh vien theo diem TB tang dan        |\n");
    printf("| 3. Tim kiem sinh vien theo ma so sinh vien        |\n");
    printf("| 4. Xuat danh sach sinh vien dat hoc bong(>=8.0)   |\n");
    printf("| 5. Thoat chuong trinh                             |\n");
    printf("+---------------------------------------------------+\n");
}

void chucNang1(struct SinhVien ds[], int *n)
{
    do
    {
        printf("Nhap so luong sinh vien n: ");
        if (scanf("%d", n) != 1)
        {
            while (getchar() != '\n')
                ;
            *n = -1;
            continue;
        }
        while (getchar() != '\n')
            ;

        if (*n <= 0)
        {
            printf("So luong sinh vien phai lon hon 0. Vui long nhap lai!\n");
        }
    } while (*n <= 0);

    printf("\nNHAP THONG TIN %d SINH VIEN\n", *n);
    for (int i = 0; i < *n; i++)
    {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);

        printf("  - MSSV: ");
        fgets(ds[i].mssv, sizeof(ds[i].mssv), stdin);
        ds[i].mssv[strcspn(ds[i].mssv, "\n")] = 0;

        printf("  - Ho va ten: ");
        fgets(ds[i].tenSV, sizeof(ds[i].tenSV), stdin);
        ds[i].tenSV[strcspn(ds[i].tenSV, "\n")] = 0;

        printf("  - Nganh hoc: ");
        fgets(ds[i].nganhHoc, sizeof(ds[i].nganhHoc), stdin);
        ds[i].nganhHoc[strcspn(ds[i].nganhHoc, "\n")] = 0;

        printf("  - Diem TB: ");
        scanf("%f", &ds[i].diemTB);
        while (getchar() != '\n')
        ;
    }

    printf("\n======================================================================================\n");
    printf("| %-15s | %-25s | %-25s | %-7s |\n", "MSSV", "Ho va ten", "Nganh hoc", "Diem TB");
    printf("======================================================================================\n");
    for (int i = 0; i < *n; i++)
    {
        printf("| %-15s | %-25s | %-25s | %-7.2f |\n",
               ds[i].mssv, ds[i].tenSV, ds[i].nganhHoc, ds[i].diemTB);
    }
    printf("======================================================================================\n");
}

void chucNang2(struct SinhVien ds[], int n)
{
    if (n <= 0)
    {
        printf("\nDanh sach hien tai dang trong. Vui long nhap thong tin o chuc nang 1 truoc!\n");
        return;
    }
    struct SinhVien temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ds[i].diemTB > ds[j].diemTB)
            {
                temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    printf("\nDANH SACH SINH VIEN SAU KHI SAP XEP (DIEM TB TANG DAN)\n");
    printf("======================================================================================\n");
    printf("| %-15s | %-25s | %-25s | %-7s |\n", "MSSV", "Ho va ten", "Nganh hoc", "Diem TB");
    printf("======================================================================================\n");

    for (int i = 0; i < n; i++)
    {
        printf("| %-15s | %-25s | %-25s | %-7.2f |\n",
               ds[i].mssv,
               ds[i].tenSV,
               ds[i].nganhHoc,
               ds[i].diemTB);
    }
    printf("======================================================================================\n");
}

void chucNang3(struct SinhVien ds[], int n)
{
    if (n <= 0)
    {
        printf("\nDanh sach hien tai dang trong. Vui long nhap thong tin o chuc nang 1 truoc!\n");
        return;
    }
    char mssvTim[50];
    int found = 0;
    printf("\nNhap Ma so sinh vien can tim: ");
    fgets(mssvTim, sizeof(mssvTim), stdin);
    mssvTim[strcspn(mssvTim, "\n")] = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(ds[i].mssv, mssvTim) == 0)
        {
            if (found == 0)
            {
                printf("\nTHONG TIN SINH VIEN TIM THAY\n");
                printf("======================================================================================\n");
                printf("| %-15s | %-25s | %-25s | %-7s |\n", "MSSV", "Ho va ten", "Nganh hoc", "Diem TB");
                printf("======================================================================================\n");
            }
            printf("| %-15s | %-25s | %-25s | %-7.2f |\n",
                   ds[i].mssv,
                   ds[i].tenSV,
                   ds[i].nganhHoc,
                   ds[i].diemTB);
            found = 1;
            break;
        }
    }
    if (found == 1)
    {printf("======================================================================================\n");
    }
    if (found == 0)
    {
        printf("\nKhong tim thay sinh vien co MSSV \"%s\" nay!\n", mssvTim);
    }
}

void chucNang4(struct SinhVien ds[], int n)
{
    {
        if (n <= 0)
        {
            printf("\nDanh sach hien tai dang trong. Vui long nhap thong tin o chuc nang 1 truoc!\n");
            return;
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds[i].diemTB >= 8.0)
            {
                count++;
            }
        }

        if (count == 0)
        {
            printf("\nKhong co sinh vien nao dat hoc bong (Diem TB >= 8.0)!\n");
            return;
        }

        printf("\nDANH SACH SINH VIEN DAT HOC BONG (DIEM TB >= 8.0)\n");

        char nganhDaDuyet[100][50];
        int soLuongNganh = 0;

        for (int i = 0; i < n; i++)
        {
            if (ds[i].diemTB >= 8.0)
            {
                int daTonTai = 0;
                for (int j = 0; j < soLuongNganh; j++)
                {
                    if (strcmp(nganhDaDuyet[j], ds[i].nganhHoc) == 0)
                    {
                        daTonTai = 1;
                        break;
                    }
                }
                if (!daTonTai)
                {
                    strcpy(nganhDaDuyet[soLuongNganh], ds[i].nganhHoc);
                    soLuongNganh++;
                }
            }
        }

        for (int i = 0; i < soLuongNganh; i++)
        {
            printf("\nNGANH HOC: %s\n", nganhDaDuyet[i]);
            printf("===================================================================\n");
            printf("| %-15s | %-35s | %-7s |\n", "MSSV", "Ho va ten", "Diem TB");
            printf("===================================================================\n");

            for (int j = 0; j < n; j++)
            {
                if (ds[j].diemTB >= 8.0 && strcmp(ds[j].nganhHoc, nganhDaDuyet[i]) == 0)
                {
                    printf("| %-15s | %-35s | %-7.2f |\n",
                           ds[j].mssv,
                           ds[j].tenSV,
                           ds[j].diemTB);
                }
            }
            printf("===================================================================\n");
        }
    }
}