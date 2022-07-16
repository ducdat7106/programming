#pragma once

#include<iostream>
#include<string>

using namespace std;

class CDocGia
{
protected:
    string hoTen;
    string ngayLamThe; //dd/MM/yyyy
    int soThangCoHieuLuc;

public:
    void input();
    void output();
    CDocGia();
    ~CDocGia();
};

