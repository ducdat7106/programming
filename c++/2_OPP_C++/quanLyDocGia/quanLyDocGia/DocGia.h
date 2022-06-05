#pragma once

#include <iostream>
#include <string>
using namespace std;

class CDocGia
{
protected:
    string hoTen;
    string ngayLamThe; // dd/MM/yyyy
    int soThangCoHieuLuc;

public:
    void input();//phương thức nhập
    void output();//phương thức xuất
    CDocGia();
    ~CDocGia();
};
