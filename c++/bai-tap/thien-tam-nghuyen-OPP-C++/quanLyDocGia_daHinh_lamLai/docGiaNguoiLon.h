#pragma once

#include "DocGia.h"

class docGiaNguoiLon :public DocGia
{
	string chungMinhThu;
public:
	docGiaNguoiLon();
	~docGiaNguoiLon();

	void input();
	void output();
	int tienLamThe();
};