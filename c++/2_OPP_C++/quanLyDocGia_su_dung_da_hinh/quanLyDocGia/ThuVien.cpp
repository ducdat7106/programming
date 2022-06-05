#include "ThuVien.h"

CThuVien::CThuVien()
{

}

CThuVien::~CThuVien()
{

}

void CThuVien::input()
{
    int luachon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t==========THU VIEN X=============";
        cout << "\n\t1. Doc gia tre em";
        cout << "\n\t2. Doc gia nguoi lon";
        cout << "\n\t0. Thoat";
        cout << "\n\n\t\t==========   END    =============";

        cout << "\nNhap lua chon: ";
        cin >> luachon;

        CDocGia* x;//khai báo con trỏ lớp cha

        if (luachon == 0)
        {
            system("cls");
            break;
        }
        else if (luachon < 0 || luachon > 2 )
        {
            cout << "\nNhap sai. Moi nhap lai!";
            system("pause");
        }
        else if (luachon == 1)
        {
            x = new CDocGiaTreEm;//dunhf thằng cha new ra 1 đối tượng trẻ em
            cout << "\n\n\t\tNHAP THONG TIN DOC GIA";
            x->input();
            x->Setter_kiemTra(true);//đánh dấu cái này lad độc giả trẻ em
            ds_docGia.push_back(x); // them 1 doi tuong con  x vao trong mang DocGia
        }
        else if (luachon == 2)
        {
            x = new CDocGiaNguoiLon;
            cout << "\n\n\t\tNHAP THONG TIN DOC GIA";
            x->input();
            x->Setter_kiemTra(false);//đánh dấu cái này lad độc giả người lớn

            ds_docGia.push_back(x); // them doi tuong x vao trong mang
        }
    }
}

void CThuVien::output()
{
    cout << "\n\n\t\t===============DANH SACH DOC GIA=================";
    for (int i = 0; i < ds_docGia.size(); i++)
    {
        if (ds_docGia[i]->Getter_kiemTra() == true)
        {
            cout << "\n\n\t\tTHONG TIN DOC GIA TRE EM THU " << i + 1;
            ds_docGia[i]->output(); //xuất ra thông tin độc giả thứ i
        }
        else
        {
            cout << "\n\n\t\tTHONG TIN DOC GIA NGUOI LON THU " << i + 1;
            ds_docGia[i]->output(); //xuất ra thông tin độc giả thứ i
        }
    } 
}

int CThuVien::tinhTongTienLamThe()
{
    int sum = 0;
    for (int i = 0; i < ds_docGia.size(); i++)
    {
        sum += ds_docGia[i]->tinhTienLamThe();
    }
    return sum;
}

