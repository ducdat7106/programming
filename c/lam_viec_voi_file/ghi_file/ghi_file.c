#include<stdio.h>
#include<stdlib.h>// contains keyword system("");

struct SinhVien
{
    int tuoi;
    char ten[30], diaChi[30];
}s,s1;

void clear_enter(char *arr)
{
    int length=0;
    while(arr[length]!='\0')
        length++;
    
    if(arr[length-1]=='\n')
        arr[length-1] = '\0';
    else    
        printf("\nKhong co su thay the!!\n");
}

void nhap()
{
    printf("Nhap ten: ");
    fflush(stdin);
    fgets(s.ten, 30, stdin);

    printf("Nhap tuoi:");
    scanf("%d",&s.tuoi);

    printf("Nhap dia chi: ");
    fflush(stdin);
    fgets(s.diaChi, 30, stdin);

    clear_enter(s.ten);
    clear_enter(s.diaChi);
}

void ghi(FILE *f)
{
    fprintf(f, "\n%s\n%d\n", s.ten, s.tuoi);
    fputs(s.diaChi, f);
}

int main()
{
    system("cls");

    // FILE *f = fopen("SinhVien.TXT", "w");    //open file new, write into file new
    FILE *f = fopen("SinhVien.TXT", "a");       //open file exist, write into end of file

    nhap();
    ghi(f);

    return 0;
}
