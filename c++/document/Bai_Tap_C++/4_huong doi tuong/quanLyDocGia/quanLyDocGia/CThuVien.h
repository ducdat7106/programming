#pragma once

#include "CDocGiaNguoiLon.h"
#include "CDocGiaTreEm.h"
#include<vector>

class CThuVien
{
private:
    vector<CDocGiaTreEm *> ds_docGiaTreEm;
    vector<CDocGiaNguoiLon *> ds_docGiaNguoiLon;
public:
    void input();
    void output();
    int tinhTongTienLamThe();

    CThuVien();
    ~CThuVien();
};

