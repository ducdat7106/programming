#include <iostream>
using namespace std;

typedef int ElementType;

struct Node
{
    ElementType Element;
    Node *Next;
};

typedef struct Node Node;
typedef Node *Position;
typedef Position List;

void MakeNull_List(List &Header) // Khởi tạo danh sách rỗng
{
    Header = (Node *)malloc(sizeof(Node));
    Header->Next = NULL;
}

int Empty_List(List L) // kiểm tra danh sách rỗng, nếu rỗng trả về 1, không rỗng trả về 0
{
    return (L->Next == NULL);
}

Position First_List(List L) // Trả về đầu danh sách
{
    return L;
}

Position Next_List(Position P, List L)
{
    return P->Next;
}

Position End_List(List L) // Cho biết vị trí cuối danh sách
{
    Position P;
    P = L;
    while (P->Next != NULL)
        P = P->Next;
    return P;
}

void Insert_List(ElementType X, Position P, List &L) // Chèn phần tử X vào danh sách L tại vị trí P
{
    Position T;
    T = (Node *)malloc(sizeof(Node));
    T->Element = X;
    T->Next = P->Next;
    P->Next = T;
}

void Insert_First_List(ElementType X, List &L) // Chèn phần tử X vào đầu danh sách
{
    Insert_List(X, First_List(L), L);
}

void Insert_End_List(ElementType X, List &L) // Chèn X vào cuối danh sách
{
    Insert_List(X, End_List(L), L);
}

void Delete_List(Position P, List &L) // Xóa phần tử thứ P trong danh sách L
{
    Position Temp;
    if (P->Next != NULL)
    {
        Temp = P->Next;
        P->Next = Temp->Next;
        free(Temp);
    }
}

Position Locate(ElementType X, List L) //Định vị vị trí của X trong danh sach L
{
    Position P = L;
    while (P->Next != NULL)
        if (P->Next->Element == X)
            break;
        else
            P = P->Next;
    return P;
}

ElementType Retrieve(Position P, List L) // Trả về giá trị tại vị trí P trong danh sách L
{
    if (P->Next != NULL)
        return P->Next->Element;
}

void Read_List(List &L) // Nhập danh sách vào
{
    int n, i = 0;
    cout << "\tNhap so phan tu cua danh sach: ";
    cin >> n;

    ElementType X;
    while (i < n)
    {
        cout << "\t-Nhap phan tu thu " << i + 1 <<" ";
        cin >> X;
        Insert_End_List(X, L);
        i++;
    }
}

void Print_List(List &L) // In danh sách ra
{
    Position P = First_List(L);
    while (P->Next != NULL)
    {
        cout << P->Next->Element << " ";
        P = P->Next;
    }
}

void Print_Rev_List(List L) // In danh sách nghịch đảo ra
{

    if (L->Next != NULL)
    {
        Position P = L->Next;
        if (P->Next == NULL)
            cout << P->Element<<" ";
        else
        {
            Print_Rev_List(L->Next);
            cout << P->Element<<" ";
        }
    }
}

void Distinct(List &L) // Lọc xóa các phần tử trùng nhau
{
    Position P, Q;

    for (P = L; P->Next != NULL; P = P->Next)
        for (Q = P->Next; Q->Next != NULL;)
            if (P->Next->Element == Q->Next->Element)
                Delete_List(Q, L);
            else
                Q = Q->Next;
}

void Swap(Position &x1, Position &x2)
{
    ElementType Temp = x1->Next->Element;
    x1->Next->Element = x2->Next->Element;
    x2->Next->Element = Temp;
}

void Sort(List &L) // sắp xếp danh sách theo thứ tự tăng dần
{
    Position P, Q;
    ElementType Temp;

    for (P = L; P->Next != NULL; P = P->Next)
        for (Q = P->Next; Q->Next != NULL; Q = Q->Next)
            if (P->Next->Element > Q->Next->Element)
                Swap(P, Q);
}

int Element_Counter(List L)
{
    int soPhanTu = 0;
    Position P = First_List(L);
    while (P != End_List(L))
    {
        soPhanTu++;
        P = Next_List(P, L);
    }
    return soPhanTu;
}

main()
{
    system("cls");

    List L;
    ElementType X = 500;
    Position P;
    MakeNull_List(L);

    Read_List(L);
    cout << "\n\t-> 1_Danh sach vua nhap: \n";
    Print_List(L);

    // cout << "\n->2_Danh dach nghich dao\n";
    // Print_Rev_List(L);
    // cout << endl;

    // Sort(L);
    // printf("\n\t->3_Danh sach da sap xep: \n");
    // Print_List(L);
    // cout << endl;

    // Distinct(L);
    // printf("\n\t->4_Danh sach da xoa cac phan tu trung nhau: \n");
    // Print_List(L);
    // cout << endl;

    // cout<<"\n5_So phan tu trong danh sach "<<Element_Counter(L)<<endl;

    // Insert_First_List(X, L);
    // printf("\n\t->6_Danh sach da them phan tu vao dau: \n");
    // Print_List(L);

    // Insert_End_List(X, L);
    // printf("\n\t->7_Danh sach da them phan tu vao cuoi: \n");
    // Print_List(L);

    // cout<<"\n8_Gia tri can xoa: ";
    // cin>>X;
    // P=Locate(X, L);
    // Delete_List(P, L);
    // cout<<"\nDanh sach phan tu sau khi xoa "<<X<<" la \n";
    // Print_List(L);

    Position viTri;
    cout << "\n9_Phan tu can them vao danh sach: ";
    cin >> X;
    cout << "Vi tri can them: ";
    cin >> viTri->Element;
    Insert_List(X, viTri, L);
    cout<<"\nDanh sach sau khi them:\n";
    Print_List(L);

    cout << endl;
    system("pause");
}
