#include <stdio.h>
#include <stdlib.h> // contains keyword system("");
struct SinhVien
{
    int tuoi;
    char ten[30], diaChi[30];
} s, s1;

void clear_enter(char *arr)
{
    int length = 0;
    while (arr[length] != '\0')
        length++;

    if (arr[length - 1] == '\n')
        arr[length - 1] = '\0';
    else
        printf("\nKhong co su thay the!!\n");
}

void nhap()
{
    printf("Nhap ten: ");
    scanf("%s", &s.ten);

    printf("Nhap tuoi:");
    scanf("%d", &s.tuoi);

    printf("Nhap dia chi: ");
    fflush(stdin);
    fgets(s.diaChi, 30, stdin);

    clear_enter(s.diaChi);
}

void ghi(FILE *f)
{
    fprintf(f, "\n%s\n%d\n", s.ten, s.tuoi);
    fputs(s.diaChi, f);
}

void doc(FILE *f)
{
    fscanf(f, "%s", &s1.ten);
    fscanf(f, "%d", &s1.tuoi);

    // loai bo ky tu dem thua thai
    char tx[5];
    fgets(tx, 5, f);

    fgets(s1.diaChi, 20, f);
}

void xuat()
{
    printf("\nTen: %s\nTuoi: %d\nDia Chi: %s", s1.ten, s1.tuoi, s1.diaChi);
}

int main()
{
    system("cls");

    // FILE *f = fopen("SinhVien1.TXT", "w");
    // FILE *f = fopen("SinhVien1.TXT", "a");
    FILE *f = fopen("SinhVien1.TXT", "r");

    // nhap();
    // ghi(f);

    while (!feof(f))
    {
        doc(f);
        xuat();
    }

    fclose(f);

    return 0;
}

/*
    cách chữa lỗi lặp lại kết quả cuối:

    xóa ký tự xuống dòng trống trống trong file cần đọc
*/