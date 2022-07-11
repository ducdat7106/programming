#include "DocGiaTreEm.h"

void CDocGiaTreEm::input()
{
    CDocGia::input();

    cin.ignore();
    cout << "\nho ten nguoi dai dien: ";
    getline(cin, hotenNguoiDaiDien);
}

void CDocGiaTreEm::output()
{
    CDocGia::output();

    cout << "\nho ten nguoi dai dien: " << hotenNguoiDaiDien;
}

int CDocGiaTreEm::tinhTienLamThe()
{
    return soThangCoHieuLuc * 5000;
}

CDocGiaTreEm::CDocGiaTreEm()
{
    hotenNguoiDaiDien = "";
}

CDocGiaTreEm::~CDocGiaTreEm()
{
    hotenNguoiDaiDien = "";
}