/*
Chúng ta sẽ tìm hiểu các vấn đề cơ bản sau:

    Cài đặt danh sách (Khai báo)
    Khởi tạo danh sách rỗng
    Kiểm tra danh sách rỗng (danh sách đầy khi cài bằng mảng)
    Chèn phần tử vào đầu danh sách
    Chèn phần tử vào vị trí thứ k trong danh sách
    Nhập danh sách
    Xuất danh sách
    Tìm 1 phần tử trong danh sách
    Xóa phần tử đầu tiên trong danh sách
    Xóa phần tử thứ k trong danh sách
    Xóa phần tử có nội dung X trong danh sách
*/

#include <iostream>

using namespace std;

//(elementType này là kiểu dữ liệu tổng quan, khi làm nó sẽ là kiểu int, float hay kiểu cấu trúc sinh viên).
typedef int ElementType;

struct Node
{
    ElementType Element; // Thành phần thức 1: Biến nguyên chứa dữ liệu
    struct Node *Next;   // Thành phần thứ 2: 1 con trỏ chứa địa chỉ của nút kế tiếp
};

typedef struct Node Node; // Định nghĩa 1 kiểu dữ liệu con trỏ tới nút có tên Node

typedef Node *Position;

typedef Position List;

// Khởi tạo danh sách rỗng
void Make_Null_List(List *Header)
{
    (*Header) = (Node *)malloc(sizeof(Node));
    (*Header)->Next = NULL;
}

/*
//C
void Make_Null_List(List *Header) {
    (*Header)=(Node*)malloc(sizeof(Node));
    (*Header)->Next= NULL;
}

//C++
void Make_Null_List(List &Header)
{
    Header = new Node[sizeof(Node)];
    Header->Next = NULL;
}
*/

// Check danh sách rỗng, nếu rỗng trả về 1, không rỗng trả về 0
int Empty_List(List L)
{
    return (L->Next == NULL);
}

// Trả về đầu danh sách
Position First_List(List L)
{
    return L;
}

Position End_List(List L)
{
    Position P;
    P = First_List(L);
    while (P->Next != NULL)
        P = P->Next;
    return P;
}

Position Next_List(Position P, List L)
{
    return P->Next;
}

// Chèn phần tử X vào danh sách L tại vị trí P
void Insert_List(ElementType X, Position P, List &L)
{
    Position Temp; //Create node new
    Temp = (Node *)malloc(sizeof(Node)); //memory allocation node new. This node pointed to by Temp
    Temp->Element = X; //assign the appropriate value 
    Temp->Next = P->Next;
    P->Next = Temp;
}

void InsertList1(ElementType X, int P1, List *L)
{
    Position P;
    P = *L;
    while ((P->Next != NULL) && (P1 > 1))
    {
        P = P->Next;
        P1--;
    }
    Insert_List(X, P, *L);
}

// Chèn phần tử X vào đầu danh sách
void Insert_First_List(ElementType X, List &L)
{
    Insert_List(X, First_List(L), L);
}

// Chèn X vào cuối danh sách
void Insert_End_List(ElementType X, List &L)
{
    Insert_List(X, End_List(L), L);
}

// Xóa phần tử thứ P trong danh sách L
void Delete_List(Position P, List &L)
{
    Position Temp;
    if (P->Next != NULL)
    {
        Temp = P->Next;
        P->Next = Temp->Next;
        free(Temp);
    }
}

//Định vị vị trí của X trong danh sach L
Position Locate(ElementType X, List L)
{
    Position P = L;
    while (P->Next != NULL)
        if (P->Next->Element == X)
            break;
        else
            P = P->Next;
    return P;
}

/*
Position Locate(ElementType X, List L) {
    Position P;
    int Found = 0;
    P = L;
    while ((P->next != NULL) && (Found == 0))
        if (P->next->element == X) Found = 1;
        else P = P->next;
    return P;
}
*/

// Trả về giá trị tại vị trí P trong danh sách L
ElementType Retrieve(Position P, List L)
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
        cout << "\t-Nhap phan tu thu " << i + 1 << " ";
        cin >> X;
        Insert_End_List(X, L);
        i++;
    }
}

// In danh sách ra
void Print_List(List &L)
{
    Position P = First_List(L);
    while (P->Next != NULL)
    {
        cout << P->Next->Element << " ";
        P = P->Next;
    }
}

// In danh sách nghịch đảo ra
void Print_Rev_List(List L)
{

    if (L->Next != NULL)
    {
        Position P = L->Next;
        if (P->Next == NULL)
            cout << P->Element << " ";
        else
        {
            Print_Rev_List(L->Next);
            cout << P->Element << " ";
        }
    }
}

// Lọc xóa các phần tử trùng nhau
void Distinct(List &L)
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

// sắp xếp danh sách theo thứ tự tăng dần
void Sort(List &L)
{
    Position P, Q;
    ElementType Temp;

    for (P = L; P->Next != NULL; P = P->Next)
        for (Q = P->Next; Q->Next != NULL; Q = Q->Next)
            if (P->Next->Element > Q->Next->Element)
                Swap(P, Q);
}

//Đếm số phần tử trong danh sách liên kết
int Element_Counter(List L)
{
    int numberElement = 0;
    Position P = First_List(L);
    while (P != End_List(L))
    {
        numberElement++;
        P = Next_List(P, L);
    }
    return numberElement;
}



int main()
{
    system("cls");

    List L;
    ElementType X;
    Position P;

    // Make_Null_List(L);//trong C++, sử dụng tham chiếu
    Make_Null_List(&L);

    Read_List(L);
    cout << "\n\t-> 1_List just entered: \n";
    Print_List(L);

    cout << "\n->2_Inverse List\n";
    Print_Rev_List(L);
    cout << endl;

    cout << "\nElement add end list: \n";
    Insert_List(X, End_List(L), L);
    cout << "\nList after add element: \n";
    Print_List(L);

    // Sort(L);
    // printf("\n\t->3_Danh sach da sap xep: \n");
    // Print_List(L);
    // cout << endl;

    // Distinct(L);
    // printf("\n\t->4_Danh sach da xoa cac phan tu trung nhau: \n");
    // Print_List(L);
    // cout << endl;

    Position viTri;
    cout << "\n9_Element need add into list: ";
    cin >> X;
    cout << "Position need add: ";
    cin >> viTri->Element;
    Insert_List(X, viTri, L);
    cout << "\nList after adding:\n";
    Print_List(L);

    cout << "\n8_Value need delete: ";
    cin >> X;
    P = Locate(X, L);
    Delete_List(P, L);
    cout << "\nList element after delete " << X << " is \n";
    Print_List(L);

    cout << "\n5_Number element in list: " << Element_Counter(L) << endl;

    cout << endl;
    system("pause");
    return 0;
}
