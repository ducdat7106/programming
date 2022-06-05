#include "ThuVien.h"

int main()
{
    CThuVien* x = new CThuVien;


    x->input();


    x->output();

    cout << "\n\n\nTONG TIEN LAM THE: " << x->tinhTongTienLamThe();

    delete x;
    x = NULL;

    system("pause");
    return 0;
}