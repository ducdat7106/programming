#include <iostream>

using namespace std;

#define Maxlength 1000

typedef int Element_Type;
typedef int Position; // chỗ/ vị trí

typedef struct
{
    Element_Type Elements[Maxlength];
    Position Last; //Số phần tử tối đa của mảng
} List;


void MakeNull_List(List &L) // Khoi tao danh sach rỗng
{
    L.Last = 0;
}

int Empty_List(List &L) // Kiem tra sanh sach co rong hay khong| neu rong tra ve 1, nguoc lai tra ve 0
{
    return L.Last == 0;
}

int Full_List(List L)
{
    return L.Last == Maxlength;
}

Position First_List(List &L) // Trả về vị trí đầu danh sách
{
    return 1;
}
Position End_List(List &L) // trả về vị trí cuối danh sách
{
    return L.Last + 1;
}
Position Next(Position P, List &L) // Duyệt đến vị trí kế tiếp, tức vị trí P+1
{
    return P++;
}
Position Retrieve(Position P, List &L) // Trả về giá trị tại vị trí P, tức phần tử P-1
{
    return L.Elements[P - 1];
}
void Insert_List(Element_Type X, Position P, List &L) // Chèn thêm phần tử X vào Danh sách L tại vị trí P
{
    if (L.Last == Maxlength)
        printf("\tDanh sach day!");
    else if ((P < 1) || (P > L.Last + 1))
        printf("\tVi tri khong hop le!");
    else
    {
        for (Position Q = L.Last; Q > P - 1; Q--)
            L.Elements[Q] = L.Elements[Q - 1];
        L.Elements[P - 1] = X;
        L.Last++;
    }
}
void Delete_List(Position P, List &L)
{
    if ((P < 0) || (P > L.Last))
        printf("\t Vi tri khong hop le");
    else if (Empty_List(L) == 0)
        cout << "Danh sach rong!";
    else
    {
        Position Q;
        for (Q = P; Q < L.Last; Q++)
            L.Elements[Q - 1] = L.Elements[Q];
        L.Last--;
    }
}

Position Locate(Element_Type X, List L) // Tìm kiếm phần tử X trong danh sách
{
    Position P;
    int Found = 0;
    P = First_List(L);

    while ((P != End_List(L)) && (Found == 0))
        if (Retrieve(P, L) == X)
            Found = 1;
        else
            P = Next(P, L);
    return P;
}

void Read_List(List &L) // Nhập danh sách vào
{
    int n;
    Element_Type X; // int X;
    MakeNull_List(L);
    printf("\t-Nhap so phan tu cua sanh sach: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("\t\t- Nhap phan tu thu %d: ", i);
        scanf("%d", &X);
        Insert_List(X, End_List(L), L);
    }
}
void Print_List(List &L) // In danh sách ra màn hình
{
    if (Empty_List(L))
        printf("\t=> Danh sach rong!");
    else
        for (int i = 1; i <= L.Last; i++)
            printf("%4d", Retrieve(i, L));
}
void Sort_List(List &L) // Sắp xếp các phần tử trong danh sách theo thứ tự tăng dần/ giảm dần
{
    for (int i = First_List(L) - 1; i < End_List(L) - 1; i++)
        for (int j = i + 1; j < End_List(L) - 1; j++)
            if (L.Elements[i] > L.Elements[j])
            {
                int Temp = L.Elements[i];
                L.Elements[i] = L.Elements[j];
                L.Elements[j] = Temp;
            }
}

void Distinct(List &L) // Loại bỏ các phần tử trùng nhau trong danh sách
{
    for (int i = First_List(L) - 1; i < End_List(L) - 1; i++)
        for (int j = i + 1; j < End_List(L) - 1; j++)
            if (L.Elements[i] == L.Elements[j])
                Delete_List(j, L);
}

main()
{
    system("cls");

    List L;
    Position P;

    Read_List(L);

    printf("\n==> Danh sach cua ban: \n");
    Print_List(L);

    Sort_List(L);
    printf("\n==> Danh sach cua ban da sap xep: \n");
    Print_List(L);

    Distinct(L);
    printf("\n==> Danh sach sao khi loc: \n");
    Print_List(L);

    cout << endl;
    system("pause");
    return 0;
}