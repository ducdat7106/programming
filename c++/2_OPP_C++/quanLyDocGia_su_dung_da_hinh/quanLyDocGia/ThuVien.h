#pragma once // tránh tình trạng đụng độ thư viện-trong mọi trường hợp

#include "DocGiaNguoiLon.h"
#include "DocGiaTreEm.h"
#include <vector>

class CThuVien
{
private:
    vector<CDocGia *> ds_docGia;//khai báo mảng 1 chiều chứa lớp cha - vì do có virtual cho nên nó sẽ đa hình sang được từng thằng con tương ứng
    

public:
    void input();
    void output();
    int tinhTongTienLamThe();

    CThuVien();
    ~CThuVien();
};
