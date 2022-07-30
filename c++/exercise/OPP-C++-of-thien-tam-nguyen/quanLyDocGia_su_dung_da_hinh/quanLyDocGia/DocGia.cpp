#include "DocGia.h"

void CDocGia::input()
{
    cout << "\nVao ten doc gia: ";
    //fflush(stdin);
    cin.ignore();//clear memory buffer == clear cashing
    getline(cin, hoTen);

    cout << "\nVao ngay lam the (dd/MM/yyyy): ";
    cin.ignore();
    getline(cin, ngayLamThe);

    cout << "\nnNhap so thang co hieu luc: ";
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