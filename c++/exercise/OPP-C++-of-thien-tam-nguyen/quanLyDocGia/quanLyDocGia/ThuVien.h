#pragma once // tránh tình trạng đụng độ thư viện-trong mọi trường hợp

#include "DocGiaNguoiLon.h"
#include "DocGiaTreEm.h"
#include <vector>

class CThuVien
{
private:
    vector<CDocGiaTreEm*> ds_docGiaTreEm;
    vector<CDocGiaNguoiLon*> ds_docGiaNguoiLon;

public:
    void input();
    void output();
    int tinhTongTienLamThe();

    CThuVien();
    ~CThuVien();
};
