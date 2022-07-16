#pragma once

#include<iostream>
#include<string>
#include"CDocGia.h"

using namespace std;

class CDocGiaNguoiLon:public CDocGia
{
private:
    string CMND;
public:
    void input();
    void output();
    int tinhTienLamThe();

    CDocGiaNguoiLon();
    ~CDocGiaNguoiLon();
};

