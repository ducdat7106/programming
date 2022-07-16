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
    bool kiemTra;   //true : trẻ em, false : người lớn
public:
    CDocGia();
    ~CDocGia();

    virtual void input();//phương thức nhập    //phương thức ảo
    virtual void output();//phương thức xuất    //phương thức ảo
    
    virtual  int tinhTienLamThe() = 0;//khai báo phương thức thuần ảo

    /*getter_setter kiemTra*/
    bool Getter_kiemTra() {
        return kiemTra;
    }

    void Setter_kiemTra(bool kt)//cập nhật lại dữ liệu
    {
        kiemTra = kt;
    }
};
