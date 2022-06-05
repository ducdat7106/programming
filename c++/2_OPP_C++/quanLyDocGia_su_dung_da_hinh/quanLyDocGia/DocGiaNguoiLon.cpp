#include "DocGiaNguoiLon.h"

void CDocGiaNguoiLon::input()
{
    CDocGia::input();

    cin.ignore();
    cout << "\nvao cmnd: ";
    getline(cin, CMND);
}

void CDocGiaNguoiLon::output()
{
    CDocGia::output();

    cout << "\nCMND: " << CMND;
}

int CDocGiaNguoiLon::tinhTienLamThe()
{
    return soThangCoHieuLuc * 10000;
}

CDocGiaNguoiLon::CDocGiaNguoiLon()
{
    CMND = "";
}
CDocGiaNguoiLon::~CDocGiaNguoiLon()
{
    CMND = "";
}