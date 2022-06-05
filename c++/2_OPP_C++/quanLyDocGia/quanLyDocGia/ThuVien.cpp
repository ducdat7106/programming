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

        if (luachon == 0)
        {
            system("cls");
            break;
        }
        else if (luachon > 2 || luachon < 0)
        {
            cout << "\nNhap sai. Moi nhap lai!";
            system("pause");
        }
        else if (luachon == 1)
        {
            CDocGiaTreEm* x = new CDocGiaTreEm;
            cout << "\n\n\t\tNHAP THONG TIN DOC GIA";
            x->input();
            ds_docGiaTreEm.push_back(x); // them doi tuong x vao trong mang
        }
        else if (luachon == 2)
        {
            CDocGiaNguoiLon* x = new CDocGiaNguoiLon;
            cout << "\n\n\t\tNHAP THONG TIN DOC GIA";
            x->input();
            ds_docGiaNguoiLon.push_back(x); // them doi tuong x vao trong mang
        }
    }
}

void CThuVien::output()
{
    cout << "\n\n\t\t===============DANH SACH DOC GIA TRE EM=================";
    for (int i = 0; i < ds_docGiaTreEm.size(); i++)
    {
        cout << "\n\n\t\tTHONG TIN DOC GIA TRE EM THU " << i + 1;
        ds_docGiaTreEm[i]->output();
    }

    cout << "\n\n\t\t===============DANH SACH DOC GIA NGUOI LON=================";
    for (int i = 0; i < ds_docGiaNguoiLon.size(); i++)
    {
        cout << "\n\n\t\tTHONG TIN DOC GIA NGUOI LON THU " << i + 1;
        ds_docGiaNguoiLon[i]->output();
    }
}

int CThuVien::tinhTongTienLamThe()
{
    int sum = 0;
    for (int i = 0; i < ds_docGiaTreEm.size(); i++)
    {
        sum += ds_docGiaTreEm[i]->tinhTienLamThe();
    }

    for (int i = 0; i < ds_docGiaNguoiLon.size(); i++)
    {
        sum += ds_docGiaNguoiLon[i]->tinhTienLamThe();
    }
    return sum;
}

