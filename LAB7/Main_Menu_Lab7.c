#include <stdio.h>
#include <string.h>
#include <ctype.h>
void menu();
void chucNang1();
void chucNang2();
void chucNang3();
void chucNang4();

int main()
{
    int chon;
    do
    {
        menu();
        printf("Ban hay chon chuc nang tu (1-5): ");
        scanf("%d", &chon);
        getchar();
        switch (chon)
        {
        case 1:
            chucNang1();
            break;
        case 2:
            chucNang2();
            break;
        case 3:
            chucNang3();
            break;
        case 4:
            chucNang4();
            break;
        case 5:
            printf("Ban da thoat chuong trinh");
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
    printf("+---------------------------------------------------+\n");
    printf("|             MENU CHUONG TRINH LAB 7               |\n");
    printf("+---------------------------------------------------+\n");
    printf("| 1. Dem Nguyen am va Phu am trong moi chuoi        |\n");
    printf("| 2. Dang nhap he thong (User va Password)          |\n");
    printf("| 3. Sap xep danh sach chuoi theo thu tu Alphabet   |\n");
    printf("| 4. Chuyen doi thap phan sang nhi phan(chuoi)      |\n");
    printf("| 5. Thoat chuong trinh                             |\n");
    printf("+---------------------------------------------------+\n");
}

void chucNang1()
{
    char s[50];
    char strNA[10] = "ueoai";
    int demNA = 0;
    int demPA = 0;
    printf("Nhap chuoi ky tu: ");
    fgets(s, sizeof(s), stdin);
    for (int i = 0; i < strlen(s); i++)
    {
        char c = tolower((unsigned char)s[i]);
        if (isalpha((unsigned char)c))
        {
            if (strchr(strNA, c) != NULL)
            {
                demNA++;
            }
            else
            {
                demPA++;
            }
        }
    }
    printf("Chuoi moi nhap: %s\n", s);
    printf("So nguyen am: %d\tSo phu am: %d\n", demNA, demPA);
}

void chucNang2()
{

    char User[20];
    char Password[20];
    char userSys[] = "ThanhDanh";
    char PassSys[] = "Danh742007";
    printf("User name: ");
    fgets(User, sizeof(User), stdin);
    User[strcspn(User, "\n")] = 0;
    printf("Password: ");
    fgets(Password, sizeof(Password), stdin);
    Password[strcspn(Password, "\n")] = 0;
    if (strcmp(User, userSys) == 0 && strcmp(Password, PassSys) == 0)
    {
        printf("Dang nhap thanh cong\n");
    }
    else
    {
        printf("Sai UserName hoac Password\n");
    }
}

void chucNang3()
{
    char s[5][50];
    char temp[50];
    int i, j;

    printf("Nhap danh sach chuoi\n");
    for (i = 0; i < 5; i++)
    {
        printf("Nhap chuoi/ten thu %d: ", i + 1);
        fgets(s[i], sizeof(s[i]), stdin);
        s[i][strcspn(s[i], "\n")] = 0;
    }
    for (i = 0; i < 4; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            if (strcmp(s[i], s[j]) > 0)
            {
                strcpy(temp, s[i]);
                strcpy(s[i], s[j]);
                strcpy(s[j], temp);
            }
        }
    }
    printf("\nDanh sach sau sap xep tang dan\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d. %s\n", i + 1, s[i]);
    }
}

void chucNang4()
{
    int n;
    char nhiPhan[50];
    int i = 0;
    do
    {
        printf("Nhap vao mot so nguyen duong thap phan: ");
        scanf("%d", &n);
        if (n < 0)
        {
            printf("Vui long nhap so >= 0!\n");
        }
    } while (n < 0);
    if (n == 0)
    {
        strcpy(nhiPhan, "0");
    }
    else
    {
        int temp = n;
        while (temp > 0)
        {
            int du = temp % 2;
            nhiPhan[i] = du + '0';
            i++;
            temp = temp / 2;
        }
        nhiPhan[i] = '\0';
        int len = strlen(nhiPhan);
        for (int j = 0; j < len / 2; j++)
        {
            char t = nhiPhan[j];
            nhiPhan[j] = nhiPhan[len - 1 - j];
            nhiPhan[len - 1 - j] = t;
        }
    }

    printf("So nhi phan cua %d la: %s\n", n, nhiPhan);
}