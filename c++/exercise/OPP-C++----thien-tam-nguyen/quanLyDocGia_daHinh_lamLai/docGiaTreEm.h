#pragma once

#include "DocGia.h"

class docGiaTreEm : public DocGia
{
protected:
	string hoTenNguoiDaiDien;
public:
	docGiaTreEm();
	~docGiaTreEm();

	void input();
	void output();
	int tienLamThe();
};