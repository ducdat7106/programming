#pragma once

#include <iostream>
#include <string>
#include "DocGia.h"

using namespace std;

class CDocGiaTreEm : public CDocGia
{
private:
    /* data */
    string hotenNguoiDaiDien;

public:
    void input();
    void output();
    int tinhTienLamThe();

    CDocGiaTreEm(/* args */);
    ~CDocGiaTreEm();
};
