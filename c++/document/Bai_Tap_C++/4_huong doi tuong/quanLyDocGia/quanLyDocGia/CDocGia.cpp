#include "CDocGia.h"

void CDocGia::input()
{
    
    cout << "\nvao ten doc gia: ";
    cin.ignore();
    getline(cin, hoTen);

    cout << "\nvao ngay lam the (dd/MM/yyyy): ";
    cin.ignore();
    getline(cin, ngayLamThe);

    cout << "\nnhap so thang co hieu luc: ";
    cin >> soThangCoHieuLuc;
}

void CDocGia::output()
{
    cout << "\nho ten: " << hoTen;
    cout << "\nngay lam the (dd/mm/yyyy): " << ngayLamThe;
    cout << "\nso thang co hieu luc: " << soThangCoHieuLuc;
}


CDocGia::CDocGia()
{
    soThangCoHieuLuc = 0;
}

CDocGia::~CDocGia()
{
    soThangCoHieuLuc = 0;

}
