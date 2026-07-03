#include <stdio.h>
#include <string.h>

int main() {
    // Khai báo các biến để lưu trữ thông tin
    char mssv[50];
    char ho_ten[100];
    int nam_sinh;
    int tuoi;
    float diem_tb;

    // Bước 1: Nhập dữ liệu từ bàn phím
    printf("Nhap Ma so sinh vien (MSSV): ");
    fgets(mssv, sizeof(mssv), stdin);
    mssv[strcspn(mssv, "\n")] = '\0'; // Xóa ký tự xuống dòng do fgets nhận vào

    printf("Nhap Ho va Ten: ");
    fgets(ho_ten, sizeof(ho_ten), stdin);
    ho_ten[strcspn(ho_ten, "\n")] = '\0'; // Xóa ký tự xuống dòng

    printf("Nhap Nam Sinh: ");
    scanf("%d", &nam_sinh);

    printf("Nhap Diem Trung Binh: ");
    scanf("%f", &diem_tb);

    // Bước 2: Tự động tính toán số tuổi dựa trên năm 2026
    tuoi = 2026 - nam_sinh;

    // Bước 3: Xuất dữ liệu ra màn hình theo đúng định dạng mẫu
    printf("\n"); // Xuống dòng cho thoáng
    printf("Ma so sinh vien: %s\n", mssv);
    printf("Ho Va Ten: %s\n", ho_ten);
    printf("Nam sinh: %d\n", nam_sinh);
    printf("Tuoi: %d\n", tuoi);
    printf("Diem Trung Binh: %.2f\n", diem_tb); // %.2f để lấy 2 chữ số thập phân

    return 0;
}